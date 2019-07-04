/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:40:02 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 17:16:18 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft.h"

# include <stdio.h>
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

# define WIN_W 1600
# define WIN_H 900
# define MENU_W 300
# define MENU_H 900
# define IMAGE_W 1300
# define IMAGE_H 900

# define WIN_BORD 100

# define ANGLE (M_PI / 180)
# define MOVE_STEP 10
# define ZOOM_STEP 1.03

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_I 34
# define KEY_T 17
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14

# define COLOR_O1 0xbbddcc
# define COLOR1_1 0x114b5f
# define COLOR1_3 0x88d498
# define COLOR2_1 0x776688
# define COLOR2_2 0xffcc88

# define COLOR_GREY 0xbebebe
# define COLOR_WHITE 0xffffff

typedef struct	s_points
{
	int			x0;
	int			y0;
	int			z0;
	int			x;
	int			y;
	int			z;
	int			color;
	int			x_plane;
	int			y_plane;
}				t_points;

/*
** pts[y][x]
** x starts with start_x
** y starts with 0
** z starts with start_y
*/

typedef struct	s_image
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_points	**pts;
	int			x_angle;
	int			y_angle;
	int			z_angle;
	int			width;
	int			length;
	int			height;
	int			highest;
	int			lowest;
	int			x_centre;
	int			y_centre;
	int			z_centre;
	double		zoom;
	int			x_shift;
	int			y_shift;
	int			col_scheme;
}				t_map;

/*
** read_file.c
*/
int				read_color(char *s);
int				read_file(int fd, t_map *m);
int				next_stop(char *s);
int				validate_file(int fd, t_map *m);

/*
**	draw.c
*/
void			put_pixel(t_map *m, int x, int y, int color);
void			draw_line(t_map *m, t_points pt0, t_points pt1);
void			draw_2dgrid(t_map *m, void (*projection)(t_map *, t_points **));
void			redraw_image(t_map *m);

/*
**	calculate_img.c
*/
void			make_grid(t_map *m);
double			to_radians(int degrees);

/*
**	actions.c
*/
int				key_press(int key, t_map *m);

/*
**	rotations.c
*/
void			rotate_x(t_map *m, t_points **pts);
void			rotate_z(t_map *m, t_points **pts);
void			rotate_y(t_map *m, t_points **pts);
void			zoom(t_map *m, t_points **pts);

/*
**	projection.c
*/
void			parallel(t_map *m, t_points **pts);
void			isometric(t_map *m);
void			top(t_map *m);
void			put_dots(t_map *m, void (*projection) (t_map *, t_points **));

/*
** color.c
*/
int				color_grade(int color0, int color1, int dist, int curr);
int				set_color_scheme(t_map *m, t_points pt);

#endif

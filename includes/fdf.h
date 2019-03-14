/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:40:02 by yruda             #+#    #+#             */
/*   Updated: 2019/03/14 20:17:20 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <math.h>
#include "mlx.h"
#include "libft.h"

#include <stdio.h>
#include <time.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define ABS(x)		(((x) >= 0) ? (x) : (-(x)))
#define MIN(x, y)	(((x) >= (y)) ? (y) : (x))
#define MAX(x, y)	(((x) >= (y)) ? (x) : (y))

#define WIN_W 1600
#define WIN_H 900

#define WIN_BORD 100

#define ANGLE 0.05

#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126
#define KEY_1 83
#define KEY_2 84
#define KEY_3 85
#define KEY_4 86
#define KEY_5 87
#define KEY_6 88
#define KEY_7 89
#define KEY_8 91
#define KEY_9 92

/*
COLOR PALLETE
0x114b5f
0x1a936f
0x88d498
0xc6dabf
0xf3e9d2

0xb8d8ba
0xd9dbbc
0xfcddbc
0xef959d
0x69585f

0xe8e2db
0xfab95b
0xf5564e

*/

time_t g_start;

typedef struct	s_points
{
	int			x0;// calculated original 3d coordinates
	int			y0;
	int			z0;
	int			x;//current calculated 3d coordinates
	int			y;
	int			z;
	int			color;//given
	int			x_plane;//current on 2d plane
	int			y_plane;
}				t_points;

/* pts[y][x]
** x starts with start_x
** y starts with 0
** z starts with start_y
*/

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	t_points	**pts;
	int			x_angle;
	int			y_angle;
	int			z_angle;
	int			width;
	int			length;
	int			height;
	int			x_centre;
	int			y_centre;
	int			z_centre;
}				t_map;

typedef struct s_intlst
{
	int				*numbers;
	struct s_intlst	*next;
}				t_intlst;

int				get_text_rgb(char *name);
int				read_color(char *s);
int 	 		read_file(int fd, t_map *m);

int				validate_file(int fd, t_map *m);
int				next_stop(char *s);

/*
**	draw.c
*/
void			draw_line(t_map *m, t_points pt0, t_points pt1);
void			put_dots(t_map *m, void (*projection) (t_map *, t_points **));
void			draw_2dtri(t_map *m);
void			draw_2dgrid(t_map *m, void (*projection) (t_map *, t_points **));

/*
**	calculate_img.c
*/
void			make_grid(t_map *m);
float			to_radians(int degrees);

/*
**	actions.c
*/
int				key_press(int key, t_map *m);
int				actions_m(int button, int x, int y, t_map *m);
int				actions_e(t_map *m);

/*
**	rotations.c
*/
void			rotate_x(t_map *m, t_points **pts);
void			rotate_z(t_map *m, t_points **pts);
void			rotate_y(t_map *m, t_points **pts);

/*
**	projection.c
*/
void 		   isometric(t_map *m, t_points **pts);

// t_intlst	*ft_ilstnew(size_t size);
// void		ft_ilstaddback(t_intlst **alst, t_intlst *new);
// void		ft_ilstdel(t_intlst **alst);

int 		    color_grade (t_points pt0, t_points pt1, int dist, int curr);

#endif
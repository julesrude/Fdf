/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:40:02 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 18:30:03 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <math.h>
#include "mlx.h"
#include "libft.h"

#include <stdio.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define ABS(x) (((x) >= 0) ? (x) : (-x))
#define MIN(x, y)	(((x) >= (y)) ? (y) : (x))
#define MAX(x, y)	(((x) >= (y)) ? (x) : (y))

#define WIN_W 1600
#define WIN_H 900

#define WIN_BORD 100

#define ANGLE 0.0125

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126

typedef struct	s_points
{
	int			x0;// calculated original 3d coordinates
	int			y0;// calculated original 3d coordinates
	int			z0;//		((now)what is given) or calculated original
	int			x;//current calculated 3d coordinates
	int			y;//current calculated 3d coordinates
	int			z;//current calculated 3d coordinates
	int			color;//	given
	int			x_plane;//		current
	int			y_plane;//		current
}				t_points;

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
int				actions(int key, t_map *m);
int				actions_m(int button, int x, int y, t_map *m);
int				actions_e(t_map *m);

/*
**	rotations.c
*/
void			rotate_x(t_map *m, t_points **pts);
void			rotate_z(t_map *m, t_points **pts);

/*
**	projection.c
*/
void 		   isometric(t_map *m, t_points **pts);

// t_intlst	*ft_ilstnew(size_t size);
// void		ft_ilstaddback(t_intlst **alst, t_intlst *new);
// void		ft_ilstdel(t_intlst **alst);

#endif
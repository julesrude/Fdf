/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by yruda             #+#    #+#             */
/*   Updated: 2019/04/29 11:53:49 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <sys/errno.h>

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		put_error(char *str_error)
{
	ft_putendl(str_error);
	return (1);
}

void	draw_menu(void *mlx, void *win, int color1, int color2)
{
	mlx_string_put(mlx, win, 10, 20, color2, "TURN:");
	mlx_string_put(mlx, win, 10, 20, color1, "           x-axis 2,8");
	mlx_string_put(mlx, win, 10, 40, color1, "           y-axis 4,6");
	mlx_string_put(mlx, win, 10, 60, color1, "           z-axis 7,9,1,3");
	mlx_string_put(mlx, win, 10, 80, color1, "           on numpad");
	mlx_string_put(mlx, win, 10, 140, color2, "ZOOM:");
	mlx_string_put(mlx, win, 10, 140, color1, "          '+' '-'");
	mlx_string_put(mlx, win, 10, 180, color2, "MOVE:");
	mlx_string_put(mlx, win, 10, 180, color1, "           arrows");
	mlx_string_put(mlx, win, 10, 220, color2, "ISOMETRIC:");
	mlx_string_put(mlx, win, 10, 220, color1, "           press 'I'");
	mlx_string_put(mlx, win, 10, 260, color2, "TOP VIEW:");
	mlx_string_put(mlx, win, 10, 260, color1, "           press 'T'");
	mlx_string_put(mlx, win, 10, 740, color2, "CHOOSE COLOR THEME:");
	mlx_string_put(mlx, win, 10, 760, color1, "original   'Q'");
	mlx_string_put(mlx, win, 10, 780, color1, "           'W'");
	mlx_string_put(mlx, win, 10, 780, COLOR1_1, "|");
	mlx_string_put(mlx, win, 10, 780, COLOR1_3, " |");
	mlx_string_put(mlx, win, 10, 800, color1, "           'E'");
	mlx_string_put(mlx, win, 10, 800, COLOR2_1, "|");
	mlx_string_put(mlx, win, 10, 800, COLOR2_2, " |");
}

int		init_map(t_map *m)
{
	if (!(m->mlx = mlx_init()))
		return (put_error("error: Couldn't initialize the connection between \
		your software and the display"));
	m->img = (t_image *)malloc(sizeof(t_image));
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "jules");
	m->img->ptr = mlx_new_image(m->mlx, (WIN_W - MENU_W), WIN_H);
	m->img->addr = mlx_get_data_addr(m->img->ptr, &(m->img->bpp),
			&(m->img->size_line), &(m->img->endian));
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->zoom = 1;
	m->col_scheme = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*m;
	int		fd;

	m = (t_map *)malloc(sizeof(t_map));
	if (argc == 1)
		return (put_error("usage: ./fdf map"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, (void*)0, 0) < 0)
		return (put_error(strerror(errno)));
	if (!validate_file(fd, m))
		return (put_error("error: The length of lines should be equal"));
	fd = open(argv[1], O_RDONLY);
	read_file(fd, m);
	if (init_map(m))
		return (1);
	draw_menu(m->mlx, m->win, COLOR_WHITE, COLOR_O1);
	make_grid(m);
	redraw_image(m);
	mlx_hook(m->win, 2, 0, key_press, m);
	mlx_hook(m->win, 17, 0, ft_close, m);
	mlx_loop(m->mlx);
	return (0);
}

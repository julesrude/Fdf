/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by yruda             #+#    #+#             */
/*   Updated: 2019/03/14 20:42:10 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int     main(int argc, char **argv)
{
	t_map	*m;
	int		fd;

	m = (t_map *)malloc(sizeof(t_map));
	if (argc == 1)
	{
		ft_putendl("usage: ./fdf map");
		return (0);
	}
	
	g_start = time(NULL);
	printf(COLOR_YELLOW "START: %ld\n", time(NULL) - g_start);

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, (void*)0, 0) < 0)
	{
		perror("open");
		return (0);
	}
	printf(COLOR_RED "BEFORE VALIDATION: %ld\n", time(NULL) - g_start);
	if (!validate_file(fd, m))
	{
		ft_putendl("error: The length of lines should be equal everywhere");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	
	printf(COLOR_YELLOW "BEFORE READING: %ld\n", time(NULL) - g_start);
	
	read_file(fd, m);

	printf(COLOR_YELLOW "AFTER READING: %ld\n", time(NULL) - g_start);

	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "jules");

	make_grid(m);
	//put_dots(m, &isometric);
	draw_2dgrid(m, &isometric);
	//draw_line(m, m->pts[0][0], m->pts[1][2]);

	mlx_hook(m->win, 2, 0, key_press, m);
	mlx_mouse_hook(m->win, actions_m, m);

	mlx_loop(m->mlx);

	system("leaks fdf");
	return (0);
}

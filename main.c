/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 17:35:55 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int     main(int argc, char **argv)
{
	t_map	*m;
	int		fd;

	m = (t_map *)malloc(sizeof(t_map));
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || read(fd, (void*)0, 0) < 0)
		{
			perror("open");
			return (0);
		}
		if (!validate_file(fd, m))
		{
			ft_putendl("error: The length of lines should be equal everywhere");
			return (0);
		}
		fd = open(argv[1], O_RDONLY);
		read_file(fd, m);
	}


	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "jules");

	// t_points pt0 = {0, 0, 0, get_text_rgb("cornflowerblue"), 250, 0};
	// t_points pt1 = {0, 0, 0, get_text_rgb("cornflowerblue"), 249, 250};

	make_grid(m);
	put_dots(m, &isometric);
	draw_2dgrid(m, &isometric);
	mlx_key_hook(m->win, actions, m);
	mlx_mouse_hook(m->win, actions_m, m);
	//mlx_expose_hook(m->win, actions_e, m);
	mlx_loop(m->mlx);

	system("leaks fdf");
	return (0);
}

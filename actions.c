/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:42:13 by yruda             #+#    #+#             */
/*   Updated: 2019/03/14 20:14:05 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_map *m)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(EXIT_SUCCESS);
	}
	if(key == KEY_4 || key == KEY_6)
		(key == KEY_4) ? m->z_angle++ : m->z_angle--;
	if(key == KEY_8 || key == KEY_2)
		(key == KEY_8) ? m->x_angle++ : m->x_angle--;
	if(key == KEY_7 || key == KEY_1 || key == KEY_9 || key == KEY_3)
		(key == KEY_7 || key == KEY_1) ? m->y_angle++ : m->y_angle--;
	rotate_z(m, m->pts);
	rotate_x(m, m->pts);
	rotate_y(m, m->pts);
	actions_e(m);
	return (0);
}

int		actions_m(int button, int x, int y, t_map *m)
{
	mlx_pixel_put(m->mlx, m->win, x, y, get_text_rgb("cadetblue"));
	return (0);
}

int		actions_e(t_map *m)
{
	mlx_clear_window(m->mlx, m->win);
	draw_2dgrid(m, &isometric);
	return (0);
}
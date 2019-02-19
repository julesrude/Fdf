/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:42:13 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 18:10:51 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		actions(int key, t_map *m)
{
	if (key == 53)
	{	
		mlx_destroy_window(m->mlx, m->win);
		exit(EXIT_SUCCESS);
	}
	if(key == KEY_LEFT || key == KEY_RIGHT)
	{
		if(key == KEY_LEFT)
			m->z_angle++;
		else
			m->z_angle--;
		rotate_z(m, m->pts);
	}
	if(key == KEY_UP || key == KEY_DOWN)
	{
		if(key == KEY_UP)
			m->x_angle++;
		else
			m->x_angle--;
		rotate_x(m, m->pts);
	}
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
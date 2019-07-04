/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:42:13 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 17:46:44 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press1(int key, t_map *m)
{
	if (key == KEY_LEFT)
		m->x_shift -= MOVE_STEP;
	if (key == KEY_RIGHT)
		m->x_shift += MOVE_STEP;
	if (key == KEY_DOWN)
		m->y_shift -= MOVE_STEP;
	if (key == KEY_UP)
		m->y_shift += MOVE_STEP;
	if (key == KEY_I)
		isometric(m);
	if (key == KEY_T)
		top(m);
	if (key == KEY_Q)
		m->col_scheme = 0;
	if (key == KEY_W)
		m->col_scheme = 1;
	if (key == KEY_E)
		m->col_scheme = 2;
}

int		key_press(int key, t_map *m)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_4 || key == KEY_6)
		(key == KEY_4) ? (m->z_angle += 2) : (m->z_angle -= 2);
	if (key == KEY_8 || key == KEY_2)
		(key == KEY_8) ? (m->x_angle += 2) : (m->x_angle -= 2);
	if (key == KEY_7 || key == KEY_1 || key == KEY_9 || key == KEY_3)
		(key == KEY_7 || key == KEY_1) ? m->y_angle++ : m->y_angle--;
	if (key == KEY_PLUS)
		m->zoom = ZOOM_STEP * m->zoom;
	if (key == KEY_MINUS && m->zoom > 0)
		m->zoom = m->zoom / ZOOM_STEP;
	key_press1(key, m);
	rotate_z(m, m->pts);
	rotate_x(m, m->pts);
	rotate_y(m, m->pts);
	zoom(m, m->pts);
	redraw_image(m);
	return (0);
}

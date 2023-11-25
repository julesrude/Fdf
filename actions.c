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
	if (key == KEY_1)
		m->col_scheme = 0;
	if (key == KEY_2)
		m->col_scheme = 1;
	if (key == KEY_3)
		m->col_scheme = 2;
}

int		key_press(int key, t_map *m)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(EXIT_SUCCESS);
	}

	switch (key)
	{
	case KEY_A:
		m->z_angle += 2;
		break;
	case KEY_D:
		m->z_angle -= 2;
		break;
	case KEY_W:
		m->x_angle -= 2;
		break;
	case KEY_S:
		m->x_angle += 2;
		break;

	case KEY_Q:
		m->y_angle++;
		break;
	case KEY_E:
		m->y_angle--;
		break;

	case KEY_0:
		m->zoom = m->zoom * ZOOM_IN_STEP;
	case KEY_9:
		if (m->zoom > 0)
			m->zoom = m->zoom / ZOOM_OUT_STEP;
	
	default:
		break;
	}

	key_press1(key, m);
	rotate_z(m, m->pts);
	rotate_x(m, m->pts);
	rotate_y(m, m->pts);
	zoom(m, m->pts);
	redraw_image(m);
	return (0);
}

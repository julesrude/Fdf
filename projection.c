/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:43:56 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 15:33:01 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_map *m, t_points **pts)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->length)
	{
		j = 0;
		while (j < m->width)
		{
			pts[i][j].x_plane = pts[i][j].x + m->x_shift;
			pts[i][j].y_plane = pts[i][j].z - m->y_shift;
			j++;
		}
		i++;
	}
}

void	isometric(t_map *m)
{
	m->z_angle = 45;
	m->x_angle = 35;
	m->y_angle = 0;
}

void	top(t_map *m)
{
	m->z_angle = 0;
	m->x_angle = 90;
	m->y_angle = 0;
}

void	put_dots(t_map *m, void (*projection) (t_map *, t_points **))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	projection(m, m->pts);
	while (i < m->length)
	{
		j = 0;
		while (j < m->width)
		{
			put_pixel(m, m->pts[i][j].x_plane, m->pts[i][j].y_plane,
				m->pts[i][j].color);
			j++;
		}
		i++;
	}
}

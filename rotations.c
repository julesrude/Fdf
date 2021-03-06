/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:46:39 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 14:43:42 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_map *m, t_points **pts)
{
	int		i;
	int		j;
	int		x;
	int		y;
	double	angle;

	angle = m->z_angle * ANGLE;
	i = 0;
	j = 0;
	while (i < m->length)
	{
		j = 0;
		while (j < m->width)
		{
			x = pts[i][j].x0 - m->x_centre;
			y = pts[i][j].y0 - m->y_centre;
			pts[i][j].x = x * cos(angle) - y * sin(angle) + m->x_centre;
			pts[i][j].y = x * sin(angle) + y * cos(angle) + m->y_centre;
			j++;
		}
		i++;
	}
}

void	rotate_x(t_map *m, t_points **pts)
{
	int		i;
	int		j;
	int		y;
	int		z;
	double	angle;

	angle = m->x_angle * ANGLE;
	i = 0;
	j = 0;
	{
		while (i < m->length)
		{
			j = 0;
			while (j < m->width)
			{
				y = pts[i][j].y - m->y_centre;
				z = pts[i][j].z0 - m->z_centre;
				pts[i][j].y = y * cos(angle) + z * sin(angle) + m->y_centre;
				pts[i][j].z = -y * sin(angle) + z * cos(angle) + m->z_centre;
				j++;
			}
			i++;
		}
	}
}

void	rotate_y(t_map *m, t_points **pts)
{
	int		i;
	int		j;
	int		x;
	int		z;
	double	angle;

	angle = m->y_angle * ANGLE;
	i = 0;
	j = 0;
	{
		while (i < m->length)
		{
			j = 0;
			while (j < m->width)
			{
				x = pts[i][j].x - m->x_centre;
				z = pts[i][j].z - m->z_centre;
				pts[i][j].x = x * cos(angle) + z * sin(angle) + m->x_centre;
				pts[i][j].z = -x * sin(angle) + z * cos(angle) + m->z_centre;
				j++;
			}
			i++;
		}
	}
}

void	zoom(t_map *m, t_points **pts)
{
	int		i;
	int		j;
	int		x;
	int		z;
	int		y;

	i = 0;
	j = 0;
	{
		while (i < m->length)
		{
			j = 0;
			while (j < m->width)
			{
				x = pts[i][j].x - m->x_centre;
				y = pts[i][j].y - m->y_centre;
				z = pts[i][j].z - m->z_centre;
				pts[i][j].x = x * m->zoom + m->x_centre;
				pts[i][j].y = y * m->zoom + m->y_centre;
				pts[i][j].z = z * m->zoom + m->z_centre;
				j++;
			}
			i++;
		}
	}
}

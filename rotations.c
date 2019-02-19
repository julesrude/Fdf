/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:46:39 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 18:49:51 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	centre_x(t_map *m, t_points **p)//прописати точніше
{
	return (WIN_W / 2);
}

int	centre_y(t_map *m, t_points **p)//прописати точніше
{	
	return(WIN_H / 2);
}

void	rotate_z(t_map *m, t_points **pts)
{
	int		i;
	int		j;
	int		x;
	int		y;
	float	angle;

	angle = m->z_angle * ANGLE;
	i = 0;
	j = 0;
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			x = pts[i][j].x0 - centre_x(m, pts);
			y = pts[i][j].y0 - centre_y(m, pts);
			pts[i][j].x = x * cos(angle) - y * sin(angle) + centre_x(m, pts);
			pts[i][j].y = x * sin(angle) + y * cos(angle) + centre_y(m, pts);
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
	float	angle;

	angle = m->x_angle * ANGLE;
	i = 0;
	j = 0;
	{
		while(i < m->length)
		{
			j = 0;
			while(j < m->width)
			{
				y = pts[i][j].y;
				z = pts[i][j].z/* - centre_y(m, pts)*/;
				pts[i][j].y = y * cos(angle) - z * sin(angle) + centre_y(m, pts);
				pts[i][j].z = y * sin(angle) + z * cos(angle) /*+ centre_y(m, pts)*/;
				j++;
			}
			i++;
		}
	}
}
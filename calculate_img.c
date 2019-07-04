/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:52:24 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 15:04:39 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	to_radians(int degrees)
{
	return (degrees * M_PI / 180);
}

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		find_scale(int width, int height)
{
	int scale;

	scale = 1;
	if (width > 1 && height > 1)
	{
		scale = min((IMAGE_W - WIN_BORD * 2) / (width - 1),
		(IMAGE_H - WIN_BORD * 2) / (height - 1));
	}
	else if (width <= 1 && height > 1)
		scale = (IMAGE_H - WIN_BORD * 2) / (height - 1);
	else if (height <= 1 && width > 1)
		scale = (IMAGE_W - WIN_BORD * 2) / (width - 1);
	return (scale);
}

int		mg_cycle(t_map *m, int scale, int start_x, int start_y)
{
	int	i;
	int	j;
	int	max;

	max = WIN_H;
	i = -1;
	j = 0;
	while (++i < m->length)
	{
		j = 0;
		while (j < m->width)
		{
			m->pts[i][j].x0 = start_x + scale * j;
			m->pts[i][j].y0 = scale * (m->length - i - 1);
			m->pts[i][j].z0 = (WIN_H - start_y) -
				(m->pts[i][j].z0 - m->lowest) * scale;
			if (m->pts[i][j].z0 < max)
				max = m->pts[i][j].z0;
			m->pts[i][j].x = start_x + scale * j;
			m->pts[i][j].y = scale * i;
			m->pts[i][j].z = m->pts[i][j].z0;
			j++;
		}
	}
	return (max);
}

void	make_grid(t_map *m)
{
	int	start_x;
	int	start_y;
	int scale;
	int max;

	scale = find_scale(m->width, m->height);
	start_x = (IMAGE_W - scale * (m->width - 1)) / 2;
	start_y = (IMAGE_H - scale * (m->height - 1)) / 2;
	max = mg_cycle(m, scale, start_x, start_y);
	m->x_centre = start_x + scale * (m->width - 1) / 2;
	m->y_centre = scale * (m->length - 1) / 2;
	m->z_centre = max + (WIN_H - max - start_y) / 2;
	m->highest = (WIN_H - start_y) + m->highest * scale;
	m->lowest = (WIN_H - start_y) + m->lowest * scale;
	m->height = m->highest - m->lowest;
}

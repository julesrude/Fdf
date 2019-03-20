/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:52:24 by yruda             #+#    #+#             */
/*   Updated: 2019/03/20 22:19:41 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		to_radians(int degrees)
{
	return (degrees * M_PI / 180);
}

int			min(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

void	make_grid(t_map *m)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = WIN_H;
	int scale = min((WIN_W - WIN_BORD * 2)/(m->width - 1),
		(WIN_H - WIN_BORD * 2)/(m->height - 1));		//change in future
	int	start_x = (WIN_W - scale * (m->width - 1)) / 2;
	int	start_y = (WIN_H - scale * (m->height - 1)) / 2; // change maybe
	
	printf("scale: %i\n", scale);
	printf("length: %i\n", m->length);
	printf("start_x: %i\n", start_x);
	printf("start_y: %i\n", start_y);
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			m->pts[i][j].x0 = start_x + scale * j;
			m->pts[i][j].y0 = scale * (m->length - i - 1); // question
			m->pts[i][j].z0 = (WIN_H - start_y) - m->pts[i][j].z0 * scale; // question
			if(m->pts[i][j].z0 < max)
				max = m->pts[i][j].z0;
			m->pts[i][j].x = start_x + scale * j;
			m->pts[i][j].y = scale * i;
			m->pts[i][j].z = m->pts[i][j].z0;
			j++;
		}
		i++;
	}
	m->x_centre = start_x + scale * (j - 1) / 2;
	m->y_centre = scale * (i - 1) / 2;
	m->z_centre = max + (WIN_H - max - start_y) / 2;
	printf("max: %i\n", max);
	printf("x_centre: %i\n", m->x_centre);
	printf("y_centre: %i\n", m->y_centre);
	printf("z_centre: %i\n", m->z_centre);
}

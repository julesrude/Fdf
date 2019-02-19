/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:52:24 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 18:30:35 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		to_radians(int degrees)
{
	return (degrees * M_PI / 180);
}

void	make_grid(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	int scale = MIN((WIN_W - WIN_BORD * 2)/(m->width - 1),
		(WIN_H - WIN_BORD * 2)/(m->height - 1));
	int	start_x = (WIN_W - scale * (m->width - 1)) / 2;
	int	start_y = (WIN_H - scale * (m->height - 1)) / 2; // change maybe
	
	printf("scale: %i\n", scale);
	printf("start_x: %i\n", start_x);
	printf("start_y: %i\n", start_y);
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			m->pts[i][j].x0 = start_x + scale * j;
			m->pts[i][j].y0 = start_y + scale * i;
			m->pts[i][j].z = (WIN_H - start_y) - m->pts[i][j].z0 * scale;
			m->pts[i][j].x = start_x + scale * j;
			m->pts[i][j].y = start_y + scale * i;
			//m->pts[i][j].z0 = scale * m->pts[i][j].z0;
			j++;
		}
		i++;
	}
}

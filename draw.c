/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:09:03 by yruda             #+#    #+#             */
/*   Updated: 2019/03/13 22:08:49 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_map *m, t_points pt0, t_points pt1)
{
	int		run;
	int		rise;
	int		current_diff;
	int		x = 0;
	int		y = 0;

	run = pt1.x_plane - pt0.x_plane;
	rise = pt1.y_plane - pt0.y_plane;
	current_diff = 0;
	if(rise == 0 && run == 0)
		mlx_pixel_put(m->mlx, m->win, pt0.x_plane, pt0.y_plane, pt0.color);
	else if (ABS(rise) <= ABS(run))
	{
		while (ABS(x) <= ABS(run))
		{
			mlx_pixel_put(m->mlx, m->win, pt0.x_plane + x, pt0.y_plane + y, pt0.color);
			x += run / ABS(run);
			current_diff = current_diff + ABS(rise);
			if (ABS(current_diff * 2 / ABS(run)) >= 1)
			{
				y += rise / ABS(rise);
				current_diff = current_diff - ABS(run);
			}
		}
	}
	else
		while (ABS(y) <= ABS(rise))
		{
			mlx_pixel_put(m->mlx, m->win, pt0.x_plane + x, pt0.y_plane + y, pt1.color);
			y += rise / ABS(rise);
			current_diff = current_diff + ABS(run);
			if (ABS(current_diff * 2 / ABS(rise)) >= 1)
			{
				x += run / ABS(run);
				current_diff = current_diff - ABS(rise);
			}
		}
}

void	put_dots(t_map *m, void (*projection) (t_map *, t_points **))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	projection (m, m->pts);
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			mlx_pixel_put(m->mlx, m->win, m->pts[i][j].x_plane, m->pts[i][j].y_plane, get_text_rgb("honeydew"));
			j++;
		}
		i++;
	}
}

void	draw_2dgrid(t_map *m, void (*projection) (t_map *, t_points **))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(*projection) (m, m->pts);
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			if(j < m->width - 1)
				draw_line(m, m->pts[i][j], m->pts[i][j + 1]);
			if(i < m->length - 1)
				draw_line(m, m->pts[i][j], m->pts[i + 1][j]);
			j++;
			
		}
		i++;
	}
}

void	draw_2dtri(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < m->length - 3) // HEEEEEY!
	{
		j = 0;
		while(j < m->width - 3)
		{
			// if(j < m->width - 2)
				draw_line(m, m->pts[i][j], m->pts[i + 1][j + 1]);
			// if(i < m->height - 2)
				draw_line(m, m->pts[i + 2][j], m->pts[i][j + 2]);
				draw_line(m, m->pts[i][j + 2], m->pts[i][j + 1]);
				draw_line(m, m->pts[i + 3][j + 1], m->pts[i][j + 2]);
			// if(i < m->height - 1 && j < m->width - 1) // this is the diagonal
			// 	draw_line(m, m->img[i][j], m->img[i + 1][j + 1]);
			j += 2;
		}
		i += 2;
	}
}

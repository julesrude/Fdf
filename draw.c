/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:09:03 by yruda             #+#    #+#             */
/*   Updated: 2019/03/20 21:52:17 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_map *m, int x, int y, int color)
{
	if(x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
		mlx_pixel_put(m->mlx, m->win, x, y, color);
/*	int		i;

	i = 0;
	if (x >= 0 && x <= IMAGE_W && y >= 0 && y <= IMAGE_H)
	{
		i = x * m->img.bpp / 8 + y * m->img.size_line;
		m->img.addr[i] = color;
	}*/
}
/*
void	set_background(t_image img)
{
	ft_bzero(img.addr, (IMAGE_H * img.bpp / 8) * (img.size_line));
}*/

void	draw_line(t_map *m, t_points pt0, t_points pt1)
{
	int		run;
	int		rise;
	int		current_diff;
	int		x;
	int		y;

	run = abs(pt1.x_plane - pt0.x_plane);
	rise = abs(pt1.y_plane - pt0.y_plane);
	current_diff = 0;
	x = pt0.x_plane;
	y = pt0.y_plane;
	if(rise == 0 && run == 0)
		put_pixel(m, pt0.x_plane, pt0.y_plane, pt0.color);
	else if (rise <= run)
		while (x != pt1.x_plane)
		{
			put_pixel(m, x, y, 
				color_grade(pt0, pt1, run, x - pt0.x_plane));
			(pt1.x_plane >= pt0.x_plane) ? x++ : x--;
			current_diff = current_diff + rise;
			if (current_diff * 2 / run != 0)
			{
				(pt1.y_plane >= pt0.y_plane) ? y++ : y--;
				current_diff = current_diff - run;
			}
		}
	else
		while (y != pt1.y_plane)
		{
			put_pixel(m, x, y,
				color_grade(pt0, pt1, rise, y - pt0.y_plane));
			(pt1.y_plane >= pt0.y_plane) ? y++ : y--;
			current_diff = current_diff + run;
			if (current_diff * 2 / rise != 0)
			{
				(pt1.x_plane >= pt0.x_plane) ? x++ : x--;
				current_diff = current_diff - rise;
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
			put_pixel(m, m->pts[i][j].x_plane, m->pts[i][j].y_plane, m->pts[i][j].color);
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

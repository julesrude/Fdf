/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:09:03 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 16:38:17 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_map *m, int x, int y, int color)
{
	int		i;

	i = 0;
	if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
	{
		i = x * m->img->bpp / 8 + y * m->img->size_line;
		m->img->addr[i] = color;
		m->img->addr[i + 1] = color >> 8;
		m->img->addr[i + 2] = color >> 16;
		m->img->addr[i + 3] = color >> 24;
	}
}

void	draw_2dgrid(t_map *m, void (*projection) (t_map *, t_points **))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(*projection)(m, m->pts);
	while (i < m->length)
	{
		j = 0;
		while (j < m->width)
		{
			if (j < m->width - 1)
				draw_line(m, m->pts[i][j], m->pts[i][j + 1]);
			if (i < m->length - 1)
				draw_line(m, m->pts[i][j], m->pts[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	set_background(t_image *img, char c)
{
	int		i;
	int		n;

	i = 0;
	n = IMAGE_H * (img->size_line);
	while (i < n)
	{
		ft_memset(&(img->addr[i]), c, 3);
		ft_memset(&(img->addr[i + 3]), 0, 1);
		i = i + 4;
	}
}

void	redraw_image(t_map *m)
{
	set_background(m->img, 40);
	draw_2dgrid(m, &parallel);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr,
		MENU_W, WIN_H - IMAGE_H);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:19:56 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 16:48:15 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_grade(int color0, int color1, int dist, int curr)
{
	double	frac;
	int		a;
	int		r;
	int		g;
	int		b;

	if (color0 == color1)
		return (color0);
	frac = (double)abs(curr) / (double)dist;
	a = (int)(frac * (((color1 >> 24) & 0xFF) - ((color0 >> 24) & 0xFF))
		+ (double)((color0 >> 24) & 0xFF));
	r = (int)(frac * (((color1 >> 16) & 0xFF) - ((color0 >> 16) & 0xFF))
		+ (double)((color0 >> 16) & 0xFF));
	g = (int)(frac * (((color1 >> 8) & 0xFF) - ((color0 >> 8) & 0xFF))
		+ (double)((color0 >> 8) & 0xFF));
	b = (int)(frac * (((color1) & 0xFF) - ((color0) & 0xFF)) +
		(double)((color0) & 0xFF));
	return (a << 24 | r << 16 | g << 8 | b);
}

int		set_color_scheme(t_map *m, t_points pt)
{
	if (m->col_scheme == 0)
		return (pt.color);
	else if (m->col_scheme == 1)
		return (color_grade(COLOR1_1, COLOR1_3, m->height, pt.z0 - m->lowest));
	else if (m->col_scheme == 2)
		return (color_grade(COLOR2_1, COLOR2_2, m->height, pt.z0 - m->lowest));
	return (0);
}

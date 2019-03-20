/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_grade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:19:56 by yruda             #+#    #+#             */
/*   Updated: 2019/03/20 16:46:47 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     color_grade (t_points pt0, t_points pt1, int dist, int curr)
{
	double   frac;
	int     r;
	int     g;
	int     b;

	if(pt0.color == pt1.color)
		return (pt0.color);
	frac = (double)abs(curr) / (double)dist;
	r = (int)(frac * ((pt1.color >> 16) & 0xFF - (pt0.color >> 16) & 0xFF) + (double)((pt0.color >> 16) & 0xFF));
	g = (int)(frac * ((pt1.color >> 8) & 0xFF - (pt0.color >> 8) & 0xFF) + (double)((pt0.color >> 8) & 0xFF));
	b = (int)(frac * ((pt1.color) & 0xFF - (pt0.color) & 0xFF) + (double)((pt0.color) & 0xFF));
	return (0x00 | r << 16 | g << 8 | b);
}

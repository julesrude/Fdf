/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:06:58 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 17:12:51 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	seg1(t_map *m, t_points pt0, t_points pt1, int run)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;

	rise = abs(pt1.y_plane - pt0.y_plane);
	current_diff = 0;
	x = pt0.x_plane;
	y = pt0.y_plane;
	while (x != pt1.x_plane)
	{
		put_pixel(m, x, y, color_grade(set_color_scheme(m, pt0),
			set_color_scheme(m, pt1), run, x - pt0.x_plane));
		(pt1.x_plane >= pt0.x_plane) ? x++ : x--;
		current_diff += rise;
		if (current_diff * 2 / run != 0)
		{
			(pt1.y_plane >= pt0.y_plane) ? y++ : y--;
			(current_diff -= run);
		}
	}
}

void	seg2(t_map *m, t_points pt0, t_points pt1, int run)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;

	rise = abs(pt1.y_plane - pt0.y_plane);
	current_diff = 0;
	x = pt0.x_plane;
	y = pt0.y_plane;
	while (y != pt1.y_plane)
	{
		put_pixel(m, x, y, color_grade(set_color_scheme(m, pt0),
			set_color_scheme(m, pt1), rise, y - pt0.y_plane));
		(pt1.y_plane >= pt0.y_plane) ? y++ : y--;
		current_diff += run;
		if (current_diff * 2 / rise != 0)
		{
			(pt1.x_plane >= pt0.x_plane) ? x++ : x--;
			(current_diff -= rise);
		}
	}
}

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
	if (rise == 0 && run == 0)
		put_pixel(m, pt0.x_plane, pt0.y_plane, pt0.color);
	else if (rise <= run)
		seg1(m, pt0, pt1, run);
	else
		seg2(m, pt0, pt1, run);
}

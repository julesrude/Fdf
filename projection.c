/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:43:56 by yruda             #+#    #+#             */
/*   Updated: 2019/03/14 15:38:35 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(t_map *m, t_points **pts)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < m->length)
	{
		j = 0;
		while(j < m->width)
		{
			pts[i][j].x_plane = pts[i][j].x;
			pts[i][j].y_plane = pts[i][j].z;
			j++;
		}
		i++;
    }
}

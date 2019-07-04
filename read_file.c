/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:10:24 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 17:47:07 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		ft_isdelim(char c)
{
	if (c == ' ' || c == ',' || c == '	')
		return (1);
	return (0);
}

int		next_stop(char *s)
{
	int			i;

	i = ft_wordlen(s);
	while (ft_isdelim(s[i]))
		i++;
	return (i);
}

int		read_color(char *s)
{
	int		len;
	int		result;
	int		i;

	i = ft_wordlen(s) - 1;
	len = ft_wordlen(s);
	result = 0;
	if (!ft_strnstr(s, ",0x", len) || !ft_isdigit(s[i]))
		return (0xffffff);
	while ((ft_isdigit(s[i]) || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A'
			&& s[i] <= 'F')) && i >= 0)
	{
		if (ft_isdigit(s[i]))
			result += (s[i] - '0') * ft_pow(16, len - i - 1);
		else if (s[i] >= 'a' && s[i] <= 'f')
			result += (s[i] - 'a' + 10) * ft_pow(16, len - i - 1);
		else if (s[i] >= 'A' && s[i] <= 'F')
			result += (s[i] - 'A' + 10) * ft_pow(16, len - i - 1);
		else
			return (-1);
		i--;
	}
	return (result);
}

int		rf_extra(t_map *m, char *line, int i, int j)
{
	m->pts[i][j].z0 = ft_atoi(line);
	m->highest = (m->highest < m->pts[i][j].z0)
		? m->pts[i][j].z0 : m->highest;
	m->lowest = (m->lowest > m->pts[i][j].z0)
		? m->pts[i][j].z0 : m->lowest;
	m->pts[i][j].color = read_color(line);
	return (next_stop(line));
}

int		read_file(int fd, t_map *m)
{
	char		*line;
	int			i;
	int			j;
	int			x;

	i = 0;
	m->highest = -2147483648;
	m->lowest = 2147483647;
	m->pts = (t_points**)ft_memalloc(sizeof(t_points*) * m->length);
	while (get_next_line(fd, &line))
	{
		j = 0;
		x = 0;
		m->pts[i] = (t_points*)ft_memalloc(sizeof(t_points) * m->width);
		while (line[x] != '\0')
		{
			x += rf_extra(m, &line[x], i, j);
			j++;
		}
		free(line);
		i++;
	}
	m->height = m->highest - m->lowest;
	free(line);
	return (1);
}

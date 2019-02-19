/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:10:24 by yruda             #+#    #+#             */
/*   Updated: 2019/02/19 17:18:05 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int			ft_isdelim(char c)
{
	if (c == ' ' || c == ',' || c == '	')
		return (1);
	return (0);
}

int			ft_wordlen(char *s)
{
	int			i;

	i = 0;
	while (s[i] && !ft_iswhitespace(s[i]))
		i++;
	return (i);
}

int			next_stop(char *s)
{
	int			i;

	i = ft_wordlen(s);
	while (ft_isdelim(s[i]))
		i++;
	return (i);
}

int		ft_pow(int num, int pow)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if(pow < 0)
		return (-1);
	while (i < pow)
	{
		result *= num;
		i++;
	}
	return (result);
}

int		read_color(char *s)
{
	int		len;
	int		result;
	int		i;

	i = ft_wordlen(s) - 1;
	len = ft_wordlen(s);
	result = 0;
	if(!ft_strnstr(s, ",0x", len) || !ft_isdigit(s[i]))
		return (0xffffff);
	while (ft_isdigit(s[i]) && i >= 0)
	{
		if(ft_isdigit(s[i]))
			result += (s[i] - '0') * ft_pow(16, len - i - 1);
		else if (s[i] >= 'a' && s[i] <= 'f')
			result += (s[i] - 'a' + 10) * ft_pow(16, len - i - 1);
		else
			return (-1);
		i--;
	}
	return (result);
}

int		read_file(int fd, t_map *m)
{
	char		*line;
	int			i;//
	int			j;//індекс інта, що записується. його індекс в рядку
	int			x;//просто ітерація по строці

	i = 0;
	x = 0;
	m->pts = (t_points**)ft_memalloc(sizeof(t_points*) * m->length);
	while (get_next_line(fd, &line))
	{
		j = 0;
		x = 0;
		m->pts[i] = (t_points*)ft_memalloc(sizeof(t_points) * m->width);
		while (line[x] != '\0')
		{
			m->pts[i][j].z0 = ft_atoi(&line[x]);
			m->pts[i][j].color = read_color(&line[x]);
			m->x_angle = 0;
			m->y_angle = 0;
			m->z_angle = 0;
			x += next_stop(&line[x]);
			j++;
		}
		free(line);
		i++;
	}
	m->height = 20; // CALCULATE!!!!
	free(line);
	return (1);
}

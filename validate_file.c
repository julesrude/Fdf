/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:28:25 by yruda             #+#    #+#             */
/*   Updated: 2019/04/23 14:44:10 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int		validate_chars(char *s)
{
	int			i;

	i = 0;
	while (ft_isalnum(s[i]))
	{
		if (!ft_isdigit(s[i]) || s[i] != ',' || s[i] != 'x')
			return (0);
		i++;
	}
	return (1);
}

int		word_delimiter(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

int		validate_file(int fd, t_map *m)
{
	char		*line;

	m->length = 0;
	while (get_next_line(fd, &line))
	{
		if (m->length == 0)
			m->width = ft_count_words(line);
		else if (ft_count_words(line) != m->width)
		{
			free(line);
			return (0);
		}
		free(line);
		m->length++;
	}
	free(line);
	return (1);
}

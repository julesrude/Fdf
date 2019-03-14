/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:28:25 by yruda             #+#    #+#             */
/*   Updated: 2019/03/14 20:49:39 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int		validate_chars(char *s) // put it somewhere
{
	int			i;

	i = 0;
	while(ft_isalnum(s[i]))
	{
		if(!ft_isdigit(s[i]) || s[i] != ',' || s[i] != 'x')
			return (0);
		i++;
	}
	return (1);
}

/* ЗМІНИТИ РОЗРАХУНОК МАКСИМАЛЬНОЇ ВИСОТИ 
*/

int		word_delimiter(char c) //maybe such function exists
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

int		find_height(char const *s)
{
	int				max;
	int				i;

	max = -2147483648;
	i = 0;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (word_delimiter(s[i]) && !word_delimiter(s[i + 1]))
			max = (max < ft_atoi(&s[i])) ? ft_atoi(&s[i]) : max;
		i++;
	}
	return (max);
}

int			validate_file(int fd, t_map *m)
{
	char		*line;
	int			width;

	m->length = 0;
	m->height = -2147483648;
	while (get_next_line(fd, &line))
	{
		if (m->length == 0)
			m->width = ft_count_words(line);
		else
			if(ft_count_words(line) != m->width)// ERROR handling
			{
				free(line);
				return (0);
			}
		m->height = (m->height < find_height(line)) ? find_height(line) : m->height;
		free(line);
		m->length++;
	}
	free(line);
	return (1);
}
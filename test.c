/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:32:15 by yruda             #+#    #+#             */
/*   Updated: 2019/02/02 17:44:40 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ABS(x) ((x >= 0) ? (x) : (-x))

int		ft_power(int i, int power)
{
	int		result;

	result = 1;
	while(power > 0)
	{
		result *= i;
		power--;
	}
	return (result);
}

int		hextext_toi(char *s)
{
	int		i;
	int		num;
	int		result;

	i = 7;
	result = 0;
	while(i > 1)
	{
		if(s[i] >= '0' && s[i] <= '9')
			num = s[i] - '0';
		else if(s[i] >= 'a' && s[i] <= 'z')
			num = s[i] - 'a' + 10;
		else
			num = s[i] - 'A' + 10;
		result = result + num * ft_power(16, 7 - i);
		i--;
	}
	return (result);
}

int		main()
{
	/*int x;

	x = 0;
	while (x < ABS(5))
	{
		printf("%i\n", x);
		printf("%i\n", ABS(-5));
		x++;
	}
	*/
	printf("%d\n", ft_power(2,3));
	printf("%d\n", hextext_toi("0x0AA110"));
	return (0);
}

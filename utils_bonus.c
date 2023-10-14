/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:14:37 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/10 11:06:39 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	intlen(int x)
{
	int	i;

	i = 1;
	while (x >= 10)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int x)
{
	int		j;
	int		res;
	char	*str;

	j = intlen(x);
	res = 0;
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	if (x == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	str[j] = '\0';
	j--;
	while (x > 0)
	{
		str[j] = x % 10 + '0';
		x /= 10;
		j--;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, &str[0], ft_strlen(str));
}

void	ft_putnbr(int i)
{
	char	s;

	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		s = i + '0';
		write(1, &s, 1);
	}
}

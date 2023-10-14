/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:57:04 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/10 12:50:57 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res);
}

char	*dcml_to_bits(int y)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 8);
	if (!str)
		return (NULL);
	while (i != 8)
	{
		str[i] = 0 + '0';
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (y > 0)
	{
		str[i] = y % 2 + '0';
		y /= 2;
		i++;
	}
	return (str);
}

int	msg_to_bytes(char *str, int pid)
{
	char	*ss;
	int		i;
	int		j;

	j = 7;
	i = 0;
	ss = dcml_to_bits(str[i]);
	while (str[i] != '\0')
	{
		while (j >= 0)
		{
			if (ss[j] == '1')
				kill(pid, SIGUSR2);
			else if (ss[j] == '0')
				kill(pid, SIGUSR1);
			j--;
			usleep(300);
		}
		i++;
		free(ss);
		ss = dcml_to_bits(str[i]);
		j = 7;
	}
	free(ss);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	msg_to_bytes(argv[2], pid);
	if ((kill(pid, 0) == -1))
		write(1, "error\n", 6);
	return (0);
}

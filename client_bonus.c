/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:06:12 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/10 17:41:36 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	prntmsg(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("MESSAGE RECEIVED");
}

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

void	msg_to_bytes(unsigned char *str, int pid)
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
		j = 7;
		i++;
		free(ss);
		ss = dcml_to_bits(str[i]);
	}
	free(ss);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, prntmsg);
	msg_to_bytes((unsigned char *)argv[2], pid);
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(300);
		i++;
	}
	return (0);
}

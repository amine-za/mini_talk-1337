/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:14:44 by azaghlou          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:38 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
	{
		i++;
		if (i == 8)
			return (1);
	}
	return (0);
}

int	ft_pow(int x, int y)
{
	int	res;

	res = x;
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	while (y > 1)
	{
		res *= x;
		y--;
	}
	return (res);
}

void	bnr_to_dcml(char *str)
{
	int	i;
	int	res;
	int	j;

	i = 0;
	res = 0;
	j = 7;
	while (i != 8)
	{
		if (str[i] == '1')
		{
			res += ft_pow(2, j);
		}
		if (j == 0)
			write(1, &res, 1);
		j--;
		i++;
	}
}
#include <stdio.h>

void	arranging(int sig, siginfo_t *info, void *u)
{
 	static int	x;
	static char	str[9];
	static int	n;
     
	(void)u;
	if (n != info->si_pid)
	{
		n = info->si_pid;
		x = 0;
	}
	if (sig == SIGUSR2)
		str[x++] = '1';
	else if (sig == SIGUSR1)
		str[x++] = '0';
	if (x == 8)
	{
		str[x] = '\0';
		x = 0;
		bnr_to_dcml(str);
		if (ft_check(str) == 1)
			kill(n, SIGUSR1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sgac;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sgac.sa_sigaction = arranging;
	sgac.sa_flags = SA_SIGINFO;
    void *i = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sgac, i);
		sigaction(SIGUSR2, &sgac, NULL);
		pause();
	}
	return (0);
}

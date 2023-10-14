/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:14:29 by azaghlou          #+#    #+#             */
/*   Updated: 2023/01/10 11:14:31 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int x);
void	ft_putstr(char *str);
void	ft_putnbr(int i);
int		ft_check(char *str);

#endif
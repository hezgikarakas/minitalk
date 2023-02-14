/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:57:32 by hakaraka          #+#    #+#             */
/*   Updated: 2023/02/14 09:58:25 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bits(char c, int pid)
{
	int	i;

	i = 7;
	while(i >= 0)
	{
		if(c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("please check the arguments\n", 1);
		return(0);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		char_to_bits(av[2][i++], pid);
	}
}

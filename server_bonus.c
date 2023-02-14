/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:58:56 by hakaraka          #+#    #+#             */
/*   Updated: 2023/02/14 09:59:00 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_putchar(char c)
{
        write(1, &c, 1); 
}

void	ft_putstr(char *str)
{
        int     i;  

        i = 0;
        while(str[i] != '\0')
        {   
                ft_putchar(str[i]);
                i++;
        }   
}

void	message(int nbr)
{
	static int	power;
	static int	byte;

	if(nbr == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if(power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}

int main(void)
{
	ft_putstr("| Server running PID : ");
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, message);
	signal(SIGUSR2, message);
	while (1)
		pause();
}

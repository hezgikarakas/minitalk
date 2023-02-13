#include "minitalk.h"

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

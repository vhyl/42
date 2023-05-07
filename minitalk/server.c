
#include "minitalk.h"

void    signal_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int main()
{
    ft_putnbr_fd((int)getpid(), 1);
    write(1, "\n", 1);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        usleep(SLEEP);
}
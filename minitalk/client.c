#include "minitalk.h"

void	signal_handler(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
        usleep(SLEEP);
		bit++;
	}
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 3)
        return (1);
    while (argv[2][i])
    {
            signal_handler(ft_atoi(argv[1]), argv[2][i]);
            i++;
    }
    return (0);
}

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define SLEEP 1000

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
#endif
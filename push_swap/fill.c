#include "push_swap.h"

void	fill(int argc, char *argv[], t_list **stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(ft_atoi(argv[i]), stack);
		i++;
	}
}

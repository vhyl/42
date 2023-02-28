#include "push_swap.h"
#include <stdio.h>

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;
	
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		if (fill_arg(argv[1], &a))
			return (0);
	}
	else
		if (fill(argc, argv, &a))
			return (0);
	argc = stack_size(a) + 1;
	if (argc == 4)
		ft_sort_three(&a);
	else if (argc == 6)
		ft_sort_five(&a, &b);
	else
		ft_sort(&a, &b, argc - 2);
	while (b)
		pa(&a,&b);
	return (0);
}

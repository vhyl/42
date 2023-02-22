#include "push_swap.h"

int	empty(t_list *stack)
{
	if (stack)
		return (0);
	return (1);
}

int	top(t_list *stack)
{
	if (!empty(stack))
		return (stack->data);
	return (0);
}

#include "push_swap.h"

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	int	temp;

	temp = (*b)->data;
	pop(b);
	push(temp, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	int	temp;

	temp = (*a)->data;
	pop(a);
	push(temp, b);
	write(1, "pb\n", 3);
}

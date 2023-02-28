#include "push_swap.h"

int	compare_two(t_list *stack)
{
	if (stack->data < stack->next->data)
		return (0);
	return (1);
}

int	is_sorted_asc(t_list *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_dsc(t_list *stack)
{
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min(t_list *stack)
{
	int	i;
	int	min;
	int	min_pos;

	i = 0;
	min = 2147483647;
	min_pos = 0;
	while (stack)
	{
		if (min > stack->data)
		{
			min = stack->data;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	int	min;
	
	if (size == 0)
		return ;
	while (!(empty(*a)))
	{
		min = find_min(*a);
		if (min > size / 2)
		{
			while (min <= size)
			{
				rra(a);
				min++;
			}
		}
		else
		{
			while (min != 0)
			{
				ra(a);
				min--;
			}
		}
		pb(a, b);
		size--;
	}
}

void	ft_sort_three(t_list **a)
{
	if (is_sorted_asc(*a))
		return ;
	if (compare_two(*a) && find_min(*a) == 1)
	{
		if ((*a)->data > (*a)->next->next->data)
			ra(a);
		else
			sa(a);
	}
	else if (is_sorted_dsc(*a))
	{
		sa(a);
		rra(a);
	}
	else if (find_min(*a) == 2)
		rra(a);
	else
	{
		sa(a);
		ra(a);
	}
}
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf(" %d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}
void	ft_sort_five(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	ft_sort_three(a);
	if (top(*b) < top(*a))
		pa(a, b);
	else if (top(*b) > (*a)->next->next->data)
	{
		pa(a, b);
		ra(a);
	}
	print_stack(*a);
}

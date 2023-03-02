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

int	find_pos(t_list *a, int num)
{
	int	pos;

	pos = 0;
	if (top(a) > num)
		return (pos);
	while (a->next)
	{
		pos++;
		if (a->data < num && a->next->data > num)
			return (pos);
		a = a->next;
	}
	pos++;
	return (pos);
}

void	ft_sort_five(t_list **a, t_list **b)
{
	int	temp;

	temp = 0;
	pb(a, b);
	pb(a, b);
	ft_sort_three(a);
	if ((*b)->data > (*b)->next->data)
		sb(b);
	temp = find_pos((*a), top(*b));
	pa(a, b);
	if (temp == 3)
		ra(a);
	else if (temp == 2)
	{
		rra(a);
		sa(a);
		ra(a);
		ra(a);
	}
	else if (temp == 1)
		sa(a);
	temp = find_pos((*a), top(*b));
	if (temp != 2 && temp != 3)
		pa(a, b);
	if (temp == 4)
		ra(a);
	if (temp == 3)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else if (temp == 2)
	{
		ra(a);
		ra(a);
		pa(a, b);
		rra(a);
		rra(a);
	}
	else if (temp == 1)
		sa(a);
}

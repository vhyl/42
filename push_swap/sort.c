/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <vhyl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:12:18 by vhyl              #+#    #+#             */
/*   Updated: 2023/03/05 22:21:45 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf(" %d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

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

int	find_max(t_list *stack)
{
	int	i;
	int	max;
	int	max_pos;

	i = 0;
	max = -2147483648;
	max_pos = 0;
	while (stack)
	{
		if (max < stack->data)
		{
			max = stack->data;
			max_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_pos);
}

void	move_min(t_list **a, t_list **b, int *size, int *min)
{
		if (*min > *size / 2)
		{
			while (*min <= *size)
			{
				rra(a);
				*min = *min + 1;
			}
		}
		else
		{
			while (*min != 0)
			{
				ra(a);
				*min = *min - 1;
			}
		}
		pb(a, b);
		*size = *size - 1;	
}

void	move_max(t_list **a, int size, int max)
{
		if (max > size / 2)
		{
			while (max <= size)
			{
				rra(a);
				max++;
			}
		}
		else
		{
			while (max != -1)
			{
				ra(a);
				max--;
			}
		}	
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	int	min;
	int	max;
	int start_size;
	
	if (size == 0)
		return ;
	start_size = size;
	while (!is_sorted_asc(*a))
	{
		min = find_min(*a);
		max = find_max(*a);

		//printf("Min: %d, Max: %d, Size: %d\n", min, max, size);
		if (min < max || size - min > size - max || max == size)
			move_min(a, b, &size, &min);
		else
			move_max(a, size, max);
	}
	while (*b)
		pa(a, b);
	//print_stack(*a);
	//ft_sort_three(a);
	//if max is on end find next max
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

void	ft_small_sort(t_list **a, t_list **b, int size)
{
	int	min;
	
	if (size == 0)
		return ;
	while (size > 2)
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

void	ft_sort_five(t_list **a, t_list **b)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	ft_small_sort(a, b, 4);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}

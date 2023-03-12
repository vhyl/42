/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <vhyl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:12:18 by vhyl              #+#    #+#             */
/*   Updated: 2023/03/12 17:53:39 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

// int	count_chunks(int size)
// {
// 	int	i;

// 	size++;
// 	i = 0;
// 	while (size > 0)
// 	{
// 		i++;
// 		size /= 2;
// 	}
// 	return (i);
// }

int	*bubble_sort(int arr[], int size)
{
	int temp;
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*sort_arr(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		arr[i] = stack->data;
		stack = stack->next;
		i++;
	}
	arr = bubble_sort(arr, size);
	i = 0;
	// while (i <= size)
	// {
	// 	printf(" %d ", arr[i]);
	// 	i++;
	// }
	return (arr);
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

void	move_min(t_list **a, t_list **b, int *size, int min)
{
		if (min > *size / 2)
		{
			while (min <= *size)
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
		*size = *size - 1;	
}

void	move_max(t_list **a, t_list **b, int *size, int max)
{
		if (max > *size / 2)
		{
			while (max <= *size)
			{
				rra(a);
				max++;
			}
		}
		else
		{
			while (max != 0)
			{
				ra(a);
				max--;
			}
		}
		pb(a, b);
		rb(b);
		*size = *size - 1;	
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	int	min;
	int	max;

	//sort_arr(*a, size);
	//printf("Chunks: %d\n", count_chunks(size));
	if (size == 0)
		return ;
	while (!is_sorted_asc(*a))
	{
		min = find_min(*a);
		max = find_max(*a);

		//printf("Min: %d, Max: %d, Size: %d\n", min, max, size);
		if (min < size / 2 && max < size / 2)
		{
			if (min < max)
				move_min(a, b, &size, min);
			else
				move_max(a, b, &size, max);
		}
		else if (min > size / 2 && max > size / 2)
		{
			if (min > max)
				move_min(a, b, &size, min);
			else
				move_max(a, b, &size, max);
		}
		else
		{
			if (abs(min - size / 2) > abs(max - size / 2))
				move_min(a, b, &size, min);
			else
				move_max(a, b, &size, max);
		}
		//printf("Stack A\n");
		//print_stack(*a);
		//printf("Stack B\n");
		//print_stack(*b);
	}
	// while (!is_sorted_dsc(*b))
	// 	pa(a, b);
	// while (*b)
	// {
	// 	rrb(b);
	// 	pa(a, b);
	// 	ra(a);
	// }
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
	ft_small_sort(a, b, 4);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}

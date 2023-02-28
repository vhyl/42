#include "push_swap.h"

int	check_duplicates(t_list *stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = stack;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->data == temp2->data)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	fill(int argc, char *argv[], t_list **stack)
{
	int	i;
	long	temp;
	int	error;

	error = 0;
	i = argc - 1;
	while (i > 0)
	{
		temp = ft_atoi2(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			error = 1;
			break;
		}
		push((int)temp, stack);
		i--;
	}
	if (check_duplicates(*stack) || error)
	{
		write(2, "Error\n", 6);
		while (*stack)
			pop(stack);
		return (1);
	}
	return (0);
}

int	check_input(char *str)
{
	str++;
	while (*str && str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (*str == '-')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		if (!((*str >= 9 && *str <= 13) || *str == 32 || *str == 0))
			return (1);
	}
	return (0);
}

void	fill_num(char *str, t_list **stack, int *error)
{
	long	temp;
	t_list	*temp_stack;

	temp_stack = NULL;
	if (check_input(str))
		return ;
	while (*str)
	{
		temp = ft_atoi(str);
		if (temp < -2147483648 || temp > 2147483647)
			*error = 1;
		str++;
		push((int)temp, &temp_stack);
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
	}
	while (temp_stack)
	{
		temp = temp_stack->data;
		pop(&temp_stack);
		push(temp, stack);
	}
}

int	fill_arg(char *str, t_list **stack)
{
	int	error;

	error = 0;
	if (check_input(str))
		error = 1;
	else
		fill_num(str, stack, &error);
	if (check_duplicates(*stack) || error)
	{
		write(2, "Error\n", 6);
		while (*stack)
			pop(stack);
		return (1);
	}
	return (0);
}

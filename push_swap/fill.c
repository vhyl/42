#include "push_swap.h"

void	check_duplicates(t_list *stack, int *error)
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
			{
				*error = 1;
				return ;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	fill(int argc, char *argv[], t_list **stack)
{
	int	i;
	int	temp;
	int	error;

	i = 1;
	error = 0;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (temp == 0 && argv[i][0] != '0')
			error = 1;
		push(temp, stack);
		i++;
	}
	check_duplicates(*stack, &error);
	if (error)
	{
		write(2, "Error\n", 6);
		while (*stack)
			pop(stack);
	}
}

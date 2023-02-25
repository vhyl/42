#include "push_swap.h"

void	push(int value, t_list **stack)
{
	t_list	*temp = (t_list *)malloc(sizeof(t_list));
	temp->data = value;
	temp->next= *stack;
	*stack = temp;
}

void	pop(t_list **stack)
{
	t_list	*temp;
	if (*stack == NULL)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

void    rotate(t_list **stack)
{
        int     temp;
        t_list  *temp_stack;

	temp_stack = NULL;
        if (!(*stack) || !((*stack)->next))
                return ;
        temp = (*stack)->data;
        pop(stack);
        while (*stack != NULL)
        {
                push((*stack)->data, &temp_stack);
                pop(stack);
        }
        push(temp, stack);
        while (temp_stack != NULL)
        {
                push(temp_stack->data, stack);
                pop(&temp_stack);
        }
}

void	swap(t_list **stack)
{
	int	temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp_stack;
	int	temp;

	temp_stack = NULL;
	if (!(*stack) || !((*stack)->next))
		return ;
	while ((*stack)->next != NULL)
	{
		push((*stack)->data, &temp_stack);
		pop(stack);
	}
	temp = (*stack)->data;
	pop(stack);
	while (temp_stack != NULL)
	{
		push(temp_stack->data, stack);
		pop(&temp_stack);
	}
	push(temp, stack);
}

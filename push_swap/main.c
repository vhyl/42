#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_list *stack;
	fill(argc, argv, &stack);
	while (stack != NULL)
	{
		printf("%d", stack->data);
		pop(&stack);
	}
}

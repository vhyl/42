#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;
	fill(argc, argv, &a);
	if (argc <= 2)
		return (0);
	if (argc == 4)
	{
		ft_sort_three(&a);
		//return (0);
	}
	else
		ft_sort(&a, &b, argc - 2);
//	while (a)
//	{
//		printf("\n %d ", a->data);
//		a = a->next;
//	}
	while (b)
		pa(&a,&b);
//	while (a)
//	{
//		printf("\n %d ", a->data);
//		a = a->next;
//	}
	return (0);
}


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_list
{
	int	data;
	struct s_list	*next;
}	t_list;
void	push(int value, t_list **stack);
void	pop(t_list **stack);
void	rotate(t_list **stack);
void	swap(t_list **stack);
void	reverse_rotate(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int	fill(int argc, char *argv[], t_list **stack);
int	main(int argc, char *argv[]);
int	empty(t_list *stack);
int	top(t_list *stack);
void	ft_sort(t_list **a, t_list **b, int size);
void	ft_sort_three(t_list **a);
void    ft_sort_five(t_list **a, t_list **b);
int	fill_arg(char *str, t_list **stack);
int	is_sorted_asc(t_list *stack);
#endif

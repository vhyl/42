/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:46:23 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 16:11:15 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
	{
		del(start);
		return (NULL);
	}
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&start, temp);
		lst = lst->next;
	}
	return (start);
}

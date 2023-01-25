/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:27:48 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 14:35:55 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*slow;
	t_list	*fast;

	if (lst && *lst && del)
	{
		slow = *lst;
		while (slow)
		{
			fast = slow->next;
			ft_lstdelone(slow, del);
			slow = fast;
		}
		*lst = NULL;
	}
}

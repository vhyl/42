/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:37:01 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/14 23:43:23 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list ** lst, t_list *new)
{
	if (*lst == NULL)
		return ;
	while (*lst->next != NULL)
		*lst = *lst->next;
	*lst->next = new;
}

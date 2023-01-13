/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:59:32 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/13 21:28:44 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	compare(const char *str, const char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (*to_find == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (big == NULL || little == NULL)
		return (NULL);
	if (len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == *little && compare(&big[i], little)
			&& i < len - ft_strlen(little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

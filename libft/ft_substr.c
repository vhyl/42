/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:02:18 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 16:08:19 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start + len > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	if ((size_t)start > ft_strlen(s))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = 0;
		return (res);
	}
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

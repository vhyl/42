/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:23:54 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/13 21:11:30 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j])
		j++;
	if (size > i)
		res = i + j;
	else
		res = size + j;
	j = 0;
	while (size != 0 && src[j] && (i < size - 1))
		dst[i++] = src[j++];
	if (size > i)
		dst[i] = '\0';
	return (res);
}

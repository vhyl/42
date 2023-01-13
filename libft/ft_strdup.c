/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:07:00 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/13 21:55:50 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		src_len;
	char	*start;

	src_len = ft_strlen((char *)s);
	str = malloc(sizeof(char) * src_len + 1);
	start = str;
	while (*s)
	{
		*str = *s;
		str++;
		s++;
	}
	*str = '\0';
	return (start);
}

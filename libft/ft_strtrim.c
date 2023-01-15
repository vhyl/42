/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:56:07 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 20:11:28 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*empty()
{
	char	*res;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*res;
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (*set == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
        while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	size = (end - start) + 1;
	if (size < 1)
		return (empty());
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_substr(s1, start, size);
	return (res);
}

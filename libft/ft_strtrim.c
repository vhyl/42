/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:56:07 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 16:13:09 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s1[i++])
	{
		j = 0;
		while (set[j++])
			if (s1[i] == set[j])
				count++;
	}
	return (ft_strlen(s1) - count);
}

int	is_in_set(char a, char const *set)
{
	int	i;

	i = 0;
	if (a == '\0')
		return (1);
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		i;
	int		a;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	size = count_size(s1, set);
	res = malloc(size + 1);
	i = 0;
	a = 0;
	if (!res)
		return (NULL);
	while (s1[i])
	{
		if (!(is_in_set(s1[i], set)))
			res[a++] = s1[i];
		i++;
	}
	res[a] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:56:07 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/17 14:30:41 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*empty(void)
{
	char	*res;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

int	in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_size(char const *s1, char const *set)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	i = 0;
	end = 0;
	while (in_set(s1[i], set))
	{
		i++;
		start++;
	}
	while (s1[i])
		i++;
	while (in_set(s1[i - end - 1], set) && (i - end - 1) > 0)
		end++;
	return (i - (start + end));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = get_size(s1, set);
	j = 0;
	k = 0;
	if (i < 1)
		return (empty());
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (in_set(s1[j], set))
		j++;
	while (k < i)
	{
		res[k] = s1[j + k];
		k++;
	}
	res[k] = '\0';
	return (res);
}

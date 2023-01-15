/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:57:01 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/15 15:34:04 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

int	count_chars(const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		vars[3];

	if (s == 0)
		return (0);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	vars[0] = -1;
	vars[2] = 0;
	while (++vars[0] < count_words(s, c))
	{
		vars[1] = 0;
		res[vars[0]] = malloc(count_chars(s, c, vars[2]) + 1);
		if (!res[vars[0]])
			return (NULL);
		while (s[vars[2]] != '\0' && s[vars[2]] == c)
			vars[2]++;
		while (s[vars[2]] != c && s[vars[2]] != '\0')
			res[vars[0]][vars[1]++] = s[vars[2]++];
		res[vars[0]][vars[1]] = '\0';
	}
	res[vars[0]] = NULL;
	return (res);
}

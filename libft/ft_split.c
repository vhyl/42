/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:57:01 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/14 15:48:26 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i++] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**allocate(char *s, char c)
{
	int		size;
	char	**res;
	int		i;
	int		j;

	size = count_words(s, c);
	res = malloc(sizeof(char *) * (size + 1));
	i = 0;
	size = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			size++;
		else
		{
			while (s[i] == c)
				i++;
			res[j++] = malloc(sizeof(char) * size);
			size = 1;
		}
		i++;
	}
	res[j] = malloc(sizeof(char));
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int	i;
	int	j;
	int	k;

	res = allocate((char *)s, c);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			res[j][k++] = s[i];
		else
		{
			while (s[i] == c)
				i++;
			j++;
			i--;
			k = 0;
		}
		i++;
	}
	res[++j] = 0;
	return (res);
}

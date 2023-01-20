/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:37:54 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 13:40:16 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

char	**get_map(t_inp vars)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(vars.row * sizeof(char *));
	if (res == NULL)
		return (res);
	while (i < vars.row)
	{
		res[i] = malloc(vars.column * sizeof(int));
		i++;
	}
	return (res);
}

char	**fill_map(char **map, char *inp, t_inp vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (inp[k] != '\n')
		k++;
	while (i < vars.row)
	{
		j = 0;
		while (j < vars.column)
		{
			if (inp[k] == '\n')
				k++;
			map[i][j] = inp[k];
			j++;
			k++;
		}
		i++;
	}
	return (map);
}

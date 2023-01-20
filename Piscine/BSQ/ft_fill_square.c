/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:14:55 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 13:39:50 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	print(char **map, t_inp vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.row)
	{	
		j = 0;
		while (j < vars.column)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

t_pos	find_max(int	**dp, t_inp vars)
{
	t_pos curr;
	curr.y = 0;
	while (curr.y < vars.row)
	{
		curr.x = 0;
		while (curr.x < vars.column)
		{
			if (dp[curr.y][curr.x] == vars.max)
			{
				curr.y -= (vars.max - 1);
				curr.x -= (vars.max - 1);
				return (curr);
			}
			curr.x++;
		}
		curr.y++;
	}
	return (curr);
}

char	**fill_square(char **map, int **dp, t_inp vars)
{
	t_pos	curr;
	t_pos	max_pos;
	int	start_x;
	
	curr = find_max(dp, vars);
	max_pos = curr;
	start_x = curr.x;
	max_pos.y += vars.max;
	max_pos.x += vars.max;
	while (curr.y < max_pos.y)
	{
		curr.x = start_x;
		while (curr.x < max_pos.x)
		{
			map[curr.y][curr.x] = vars.square;
			curr.x++;
		}
		curr.y++;
	}
	print(map, vars);
	return (map);
}

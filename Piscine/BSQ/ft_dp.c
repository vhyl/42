/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:55:14 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 13:25:33 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	find_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

int	**ft_dp(int **dp, char **map, t_inp *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->row)
	{
		x = 0;
		while (x < vars->column)
		{
			if (map[y][x] == vars->space)
			{
				dp[y][x] = 1;
				if (y > 0 && x > 0)
				{
					dp[y][x] = find_min(dp[y - 1][x],
							dp[y][x - 1], dp[y - 1][x - 1]) + 1;
				}
				if (vars->max < dp[y][x])
					vars->max = dp[y][x];
			}
			x++;
		}
		y++;
	}
	return (dp);
}

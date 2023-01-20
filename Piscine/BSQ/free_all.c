/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:44:44 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 22:49:56 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	free_all(int **dp, char *input, t_inp vars, char **map)
{
	int	i;

	i = 0;
	while (i < vars.row)
	{
		free(dp[i]);
		free(map[i]);
		i++;
	}
	free(input);
	free(dp);
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:57:59 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 13:41:00 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	**get_dp(t_inp vars)
{
	int	**dp;
	int	i;

        dp = malloc(sizeof(int *) * vars.row);
        if (dp == NULL)
		return (NULL);
	i = 0;
	while (i < vars.row)
	{
		dp[i] = malloc(sizeof(int) * vars.column);
		i++;
	}
	return (dp);
}

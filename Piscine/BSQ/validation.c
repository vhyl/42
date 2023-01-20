/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:08:12 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 18:37:02 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	count_rows(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = -1;
	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	check_chars(char *input, t_inp vars)
{
	int	map[127];
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (input[j] != '\n')
		j++;
	while (i < 127)
		map[i++] = 0;
	while (input[j] != '\0')
	{
		if(input[j] != '\n')
			map[input[j]]++;
		j++;
	}
	map[vars.space]++;
	map[vars.obstacle]++;
	while (i >= 0)
		if (map[i--] > 0)
			count++;
	if (count != 2)
		return (1);
	return (0);
}

int	validator(char *input)
{
	t_inp	chars;
	int	i;

	i = 0;
	chars = first_row(input);
	if (chars.square == chars.space || chars.square == chars.obstacle
			|| chars.space == chars.obstacle)
		return (1);
	if (count_rows(input) != chars.row)
		return (1);
	if (check_chars(input, chars) || check_columns(input))
		return (1);
	return (0);
}

int	check_columns(char *input)
{
	int	i;
	int	first;
	int	col;

	i = 0;
	first = 0;
	col = 0;
	while (input[i] != '\n')
		i++;
	i++;
	while (input[i++] != '\n')
		first++;
	while (input[i] != '\0')
	{
		col++;
		i++;
		if (input[i] == '\n')
		{	
			if (col != first)
				return (1);
			col = 0;
			i++;
		}
	}
	return (0);
}

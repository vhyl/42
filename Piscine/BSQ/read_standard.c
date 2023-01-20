/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:58:10 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 22:51:20 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

char	**read_standard()
{	
	char	*input;
	char	**result;
	int	i;
	int	j;
	int	k;
	int	spaces;
	int	size;

	size = 0;
	input = malloc(sizeof(char) * 4096);
	read(0, input, 4096);
	spaces = 1;
	i = 0;	
	while (input[i++])
		if (input[i] == ' ')
			spaces++;
	input[i] = '\0';
	result = malloc(sizeof(char *) * (spaces + 1));
	i = 0;
	k = 0;
	while (input[k] != '\0')
	{
		size++;
		k++;
		if (input[k] == ' ' || input[k] == '\0')
		{
			result[i] = malloc(sizeof(char) * size + 1);
			size = 0;
			i++;
		}
	}
	k = 0;
	i = 0;
	j = 0;
	while (input[k] != '\0' && input[k] != '\n')
	{
		if (input[k] == ' ' || input[k] == '\0')
		{
			k++;
			i++;
			j = 0;
		}
		result[i][j] = input[k];
		j++;
		k++;
	}
	i++;
	result[i] = 0;
	free(input);
	return (result);
}

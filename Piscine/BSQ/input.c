/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:49:15 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 17:05:01 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	number_of_columns(char *str)
{
	int	i;
	int	first_row;
		
	i = 0;
	first_row = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\n')
	{
		first_row++;
		i++;
	}
	return (first_row);
}

int	number_of_rows(char *str)
{
	int	i;
	int	res;
	int	size;

	i = 0;
	size = 0;
	res = 0;
	while (str[i++] != '\n')
		size++;
	i = 0;
	while (i < size - 3)
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

t_inp	first_row(char *str)
{
	int	i;
	t_inp	first_row;

	i = 0;
	while (str[i] != '\n')
		i++;
	i--;
	first_row.square = str[i];
	first_row.obstacle = str[i - 1];
	first_row.space = str[i - 2];
	first_row.row = number_of_rows(str);
	first_row.column = number_of_columns(str);
	first_row.max = 0;
	return (first_row);
}

char	*read_input(char *name)
{
	int		op;
	char	*buff;
	int		size;
	char	*input;

	size = 0;
	op = open(name, O_RDONLY);
	buff = malloc(sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (read(op, buff, 1))
		size++;
	close(op);
	op = open(name, O_RDONLY);
	input = malloc(sizeof(char) * size);
	if (input == NULL)
		return (NULL);
	read(op, input, size);
	close(op);
	free(buff);
	return (input);
}


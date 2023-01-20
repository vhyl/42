/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:42:50 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/20 13:53:35 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*start;
	int	i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	i = 0;
	if (!buff)
		return (NULL);
	start = buff;
	while (read(fd, buff, 1) && start[i] != '\n' && i < BUFFER_SIZE)
	{
		buff++;
		i++;
	}
	if (i > 0)
		i++;
	start[i] = '\0';
	return (start);
}
/*
int main()
{
	int op;
	char *line;

	op = open("test/1-brouette.txt", O_RDONLY);
	int i = 0;

	while (i < 1000)
	{
		line = get_next_line(op);
		printf("%s", line);
		free(line);
		i++;
	}
	close(op);
}*/

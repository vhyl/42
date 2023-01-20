/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:42:50 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/20 18:05:00 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*start;
	int	i;

	if (BUFFER_SIZE == 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	ft_bzero(buff, BUFFER_SIZE + 2);
	i = 0;
	if (!buff)
		return (NULL);
	start = buff;
	while (read(fd, buff, 1) && start[i] != '\n' && i < BUFFER_SIZE)
	{
		buff++;
		i++;
	}
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:42:50 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/22 19:26:59 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_input(int fd, char *s)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buff, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_line(char *s)
{
	int	size;
	char	*res;
	int	i;

	size = 0;
	i = 0;
	if (!*s)
		return (NULL);
	while (s[size] && s[size] != '\n')
		size++;
	res = malloc(sizeof(char) * (size + 2));
	if (!res)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*next_line(char	*s)
{
	char	*res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1 - i));
	if (!res)
		return (NULL);
	i++;
	while (s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	s = read_input(fd, s);
	if (!s)
		return (NULL);
	line = get_line(s);
	s = next_line(s);
	return (line);
}
/*
int main()
{
	int op;
	char *line;
	op = open("test_2.txt", O_RDONLY);
	int i = 0; 
	while (i < 1)
	{
		line = get_next_line(op);
		printf("%s", line);
		free(line);
		i++;
	} 
	close(op);
}
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);

#endif

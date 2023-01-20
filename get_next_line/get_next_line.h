#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);

#endif

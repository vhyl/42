# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhyl <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 22:53:02 by vhyl              #+#    #+#              #
#    Updated: 2023/02/28 15:02:08 by vhyl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_strnstr.c ft_memmove.c ft_memchr.c ft_strrchr.c \
	ft_memcmp.c ft_tolower.c ft_isalnum.c ft_strlen.c \
	ft_isdigit.c ft_isprint.c ft_toupper.c ft_strlcat.c ft_bzero.c \
	ft_isalpha.c ft_memset.c ft_isascii.c ft_strlcpy.c ft_memcpy.c \
	ft_strncmp.c ft_strdup.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
	ft_strjoin.c ft_strmapi.c  ft_split.c ft_strchr.c ft_striteri.c \
	ft_strtrim.c ft_atoi2.c
		
OBJS = ${SRCS:.c=.o}

INC = libft.h

NAME = libft.a

LIBC = ar rc

LIBR = ranlib

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I/libft.h

.c.o: 
	cc ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}	
		${LIBR} ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re:		fclean all

.PHONY:		all clean fclean re

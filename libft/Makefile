# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhyl <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 15:36:30 by vhyl              #+#    #+#              #
#    Updated: 2023/01/14 15:17:05 by vhyl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_strnstr.c ft_memmove.c ft_memchr.c ft_strrchr.c \
	ft_memcmp.c ft_tolower.c ft_isalnum.c ft_strlen.c \
	ft_isdigit.c ft_isprint.c ft_toupper.c ft_strlcat.c ft_bzero.c \
	ft_isalpha.c ft_memset.c ft_isascii.c ft_strlcpy.c ft_memcpy.c \
	ft_strncmp.c ft_strdup.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
	ft_strjoin.c ft_strmapi.c ft_striteri.c ft_split.c

OBJS = ${SRCS:.c=.o}

PRE = ./srcs/

HEAD = ./includes/

NAME = libft.a

AR = ar rc

RM = rm -f

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}	
clean:
	rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re:		fclean all

.PHONY:		all clean fclean re

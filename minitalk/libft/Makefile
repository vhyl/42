# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhyl <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 22:53:02 by vhyl              #+#    #+#              #
#    Updated: 2023/01/16 19:49:04 by vhyl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_strnstr.c ft_memmove.c ft_memchr.c ft_strrchr.c \
	ft_memcmp.c ft_tolower.c ft_isalnum.c ft_strlen.c \
	ft_isdigit.c ft_isprint.c ft_toupper.c ft_strlcat.c ft_bzero.c \
	ft_isalpha.c ft_memset.c ft_isascii.c ft_strlcpy.c ft_memcpy.c \
	ft_strncmp.c ft_strdup.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
	ft_strjoin.c ft_strmapi.c  ft_split.c ft_strchr.c ft_striteri.c \
	ft_strtrim.c

SRC_BONUS = 	ft_lstiter.c ft_lstmap.c ft_lstclear.c ft_lstadd_back.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstdelone.c
		
OBJ = ${SRC:.c=.o}

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = libft.a

LIBC = ar rc

LIBR = ranlib

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: 
	cc ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJ}
		${LIBC} ${NAME} ${OBJ}	
		${LIBR} ${NAME}

bonus: ${OBJ_BONUS}
	${LIBC} ${NAME} ${OBJ_BONUS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}
fclean: clean
		rm -f ${NAME}
re:		fclean all

.PHONY:		all clean fclean re

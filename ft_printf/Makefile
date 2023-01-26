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

SRC = ft_printf.c ft_print_hexa.c ft_print_char.c ft_print_decimal.c \
	ft_print_string.c ft_print_ptr.c ft_print_unsigned.c \
	libft/ft_putchar_fd.c libft/ft_itoa.c libft/ft_putstr_fd.c \
	libft/ft_strlen.c libft/ft_bzero.c

OBJ = ${SRC:.c=.o} ${LIBFT_OBJ}

LIBFT_OBJ = ${SRC:.c=.o}

LIBFT_INC = -Ilibft

INC = ft_printf

NAME = libftprintf.a

LIBFT = libft

LIBC = ar rc

LIBR = ranlib

RM = rm -f

CFLAGS = -Wall -Wextra -Werror ${LIBFT_INC}

.c.o: 
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}
${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}
	${LIBR} ${NAME}
	-L. -l${LIBFT}

all: ${NAME} ${LIBFT}

${LIBFT}: ${LIBFT_OBJ}
	ar rc ${LIBFT} ${LIBFT_OBJ}
	ranlib ${LIBFT}

clean:
	rm -f ${OBJ} ${LIBFT_OBJ}

fclean: clean
		rm -f ${NAME}
re:		fclean all

.PHONY:		all clean fclean re

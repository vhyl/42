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

SRC = ft_printf.c

OBJ = ${SRC:.c=.o}

INC = "./libft/libft.h", ft_printf.h

NAME = ft_printf.a

LIBC = ar rc

LIBR = ranlib

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: 
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}
${NAME}: ${OBJ}
		${LIBC} ${NAME} ${OBJ}	
		${LIBR} ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}
fclean: clean
		rm -f ${NAME}
re:		fclean all


.PHONY:		all clean fclean re

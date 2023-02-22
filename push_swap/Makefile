SRCS = operations.c push_swap.c rotate.c reverse_rotate.c fill.c main.c \
       operations2.c sort.c
OBJS = ${SRCS:.c=.o}
INC = push_swap.h
NAME = push_swap
LIBC = ar rc
LIBR = ranlib
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I/push_swap.h -I/libft/libft.h

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	gcc ${OBJS} -L./libft -lft -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re


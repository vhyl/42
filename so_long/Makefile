SRCS = main.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
LIBC = ar rc
LIBR = ranlib
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@
	

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re

NAME=	libft.a

SRCS=	./srcs/is_type.c \
		./srcs/stringh.c \
		./srcs/memstr.c \
		./srcs/strsearch.c \
		./srcs/converter.c \
		./srcs/alloc_string.c \
		./srcs/ft_split.c \
		./srcs/ft_put_fd.c \
		./srcs/list.c

OBJS=	${SRCS:.c=.o}

CFLAG=	-g3 -fsanitize=address -Wall -Werror -Wextra

all:	${NAME}

%.o:%.c
		gcc ${CFLAG} -o $@ -c $<

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
		@rm -rf srcs/*.o

fclean:	clean
		@rm -rf ${NAME} a.out

re: fclean all

.PHONY: all clean fclean re
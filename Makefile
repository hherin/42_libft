NAME=	libft.a

SRCS=	./srcs/is_type.c \
		./srcs/string.c \
		./srcs/memstr.c \
		./srcs/strsearch.c \
		./srcs/converter.c \

LIBC_TEST= ./test/main.c


OBJS=	${SRCS:.c=.o}

CFLAG=	-g3 -fsanitize=address -Wall -Werror -Wextra

all:	${NAME}

%.o:%.c
		gcc ${CFLAG} -o $@ -c $<

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

test:	all
		gcc ${CFLAG} libft.a test/libmain.c -o test/lib
		gcc ${CFLAG} libft.a test/main.c -o test/home
		./test/home > ./test/homeOutput.txt
		./test/lib > ./test/libOutput.txt
		diff -u ./test/homeOutput.txt ./test/libOutput.txt

clean:
		@rm -rf srcs/*.o test/home test/homeOutput.txt test/lib test/libOutput.txt

fclean:	clean
		@rm -rf ${NAME} a.out

re: fclean all

.PHONY: all clean fclean re
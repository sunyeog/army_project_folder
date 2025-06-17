NAME = libftprintf.a
CC = cc
CFLAG = -Werror -Wextra -Wall
SRC = ft_printf.c type.c type2.c type3.c
OBJ = ${SRC:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o} 

${NAME} : ${OBJ} 	
	ar -rc ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${NAME}

re: fclean all

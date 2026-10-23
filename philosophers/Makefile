CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = main.c philo.c parsing.c time.c util.c 
OBJ = $(SRC:.c=.o)
NAME = philo
HEAD = philo.h

all: ${NAME}

${NAME} : $(OBJ) $(HEAD)
		$(CC) $(FLAG) -I./ $(OBJ) -o $(NAME)
clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
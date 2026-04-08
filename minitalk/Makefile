CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = server.c client.c 
OBJ = $(SRC:.c=.o)
NAME = client server
PRINT = ./ft_printf
PRINTA = libftprintf.a


all: ${NAME}

${NAME} : $(OBJ)
	make -C $(PRINT)
	$(CC) $(FLAG) -I./ $(SRC) -o $(NAME)  $(PRINT)/$(PRINTA)

clean :
	/bin/rm -f $(OBJ)
fclean : clean
	/bin/rm -f $(NAME)
	make -C $(PRINT) fclean
re : fclean all

CC = cc
FLAG = -Werror -Wextra -Wall 
SRC1 = server.c
SRC2 = client.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
NAME1 = server
NAME2 = client
PRINT = ./ft_printf
PRINTA = libftprintf.a


all: ${NAME}

${NAME} : $(OBJ)
	make -C $(PRINT)
	$(CC) $(FLAG) -I./ $(SRC1) -o $(NAME1)  $(PRINT)/$(PRINTA)
	$(CC) $(FLAG) -I./ $(SRC2) -o $(NAME2)  $(PRINT)/$(PRINTA)

clean :
	/bin/rm -f $(OBJ)
fclean : clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C $(PRINT) fclean
re : fclean all

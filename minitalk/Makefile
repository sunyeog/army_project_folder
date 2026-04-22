CC = cc
FLAG = -Werror -Wextra -Wall 
SRC1 = server.c
SRC2 = client.c
BON1 = server_bonus.c
BON2 = client_bonus.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
NAME1 = server
NAME2 = client
NAME3 = server_bonu
LIBA = ./libft
LIBAA = libft.a
PRINT = ./ft_printf
PRINTA = libftprintf.a


all: ${NAME1} ${NAME2}

bonus: ${NAME3} ${NAME4}

$(PRINT)/$(PRINTA):
	make -C $(PRINT)

$(LIBA)/$(LIBAA):
	make -C $(LIBA)

${NAME1} : $(OBJ1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(SRC1) -o $(NAME1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

${NAME2} : $(OBJ2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(SRC2) -o $(NAME2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

clean :
	/bin/rm -f $(OBJ1)
	/bin/rm -f $(OBJ2)
fclean : clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C $(PRINT) fclean
	make -C $(LIBA) fclean
re : fclean all

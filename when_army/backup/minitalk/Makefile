CC = cc
FLAG = -Werror -Wextra -Wall 
SRC1 = server.c
SRC2 = client.c
BSRC1 = server_bonus.c
BSRC2 = client_bonus.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
BOBJ1 = $(BSRC1:.c=.o)
BOBJ2 = $(BSRC2:.c=.o)
NAME1 = server
NAME2 = client
BON1 = server_bonus
BON2 = client_bonus
LIBA = ./libft
LIBAA = libft.a
PRINT = ./ft_printf
PRINTA = libftprintf.a


all: ${NAME1} ${NAME2}

bonus: ${BON1} ${BON2}

$(PRINT)/$(PRINTA):
	make -C $(PRINT)

$(LIBA)/$(LIBAA):
	make -C $(LIBA)

${NAME1} : $(OBJ1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(OBJ1) -o $(NAME1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

${NAME2} : $(OBJ2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(OBJ2) -o $(NAME2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

${BON1} : $(BOBJ1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(BOBJ1) -o $(BON1) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

${BON2} : $(BOBJ2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)
	$(CC) $(FLAG) -I./ $(BOBJ2) -o $(BON2) $(PRINT)/$(PRINTA) $(LIBA)/$(LIBAA)

clean :
	/bin/rm -f $(OBJ1)
	/bin/rm -f $(OBJ2)
	/bin/rm -f $(BOBJ1)
	/bin/rm -f $(BOBJ2)
fclean : clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	/bin/rm -f $(BON1)
	/bin/rm -f $(BON2)
	make -C $(PRINT) fclean
	make -C $(LIBA) fclean
re : fclean all bonus

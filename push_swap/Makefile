CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = push_swap.c push_swap_utils.c parsing.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBA = ./libft
LIBAA = libft.a


all: ${NAME}

${NAME} : $(OBJ)
	make -C $(LIBA) 
	$(CC) $(FLAG) -I./ $(SRC) -o $(NAME)  $(LIBA)/$(LIBAA)

clean :
	/bin/rm -f $(OBJ)
fclean : clean
	  /bin/rm -f $(NAME)
	  make -C $(LIBA) fclean
re : fclean all

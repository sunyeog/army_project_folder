CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = push_swap.c push_swap_utils_1.c push_swap_utils_2.c push_swap_utils_3.c parsing_1.c parsing_2.c parsing_3.c sort_1.c sort_2.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBA = ./libft
LIBAA = libft.a
PRINT = ./ft_printf
PRINTA = libftprintf.a


all: ${NAME}

${NAME} : $(OBJ)
	make -C $(LIBA)
	make -C $(PRINT)
	$(CC) $(FLAG) -I./ $(SRC) -o $(NAME)  $(LIBA)/$(LIBAA) $(PRINT)/$(PRINTA)

clean :
	/bin/rm -f $(OBJ)
fclean : clean
	/bin/rm -f $(NAME)
	make -C $(LIBA) fclean
	make -C $(PRINT) fclean
re : fclean all

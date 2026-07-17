CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = push_swap.c push_swap_utils_1.c push_swap_utils_2.c push_swap_utils_3.c parsing_1.c parsing_2.c parsing_3.c sort_1.c sort_2.c sort_3.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBA = ./libft
LIBAA = libft.a
PRINT = ./ft_printf
PRINTA = libftprintf.a
HEAD = push_swap.h


all: ${NAME}

${NAME} : $(OBJ) $(HEAD)
	make -C $(LIBA)
	make -C $(PRINT)
	$(CC) $(FLAG) -I./ $(OBJ) -o $(NAME)  $(LIBA)/$(LIBAA) $(PRINT)/$(PRINTA)

clean :
	make -C $(LIBA) clean
	make -C $(PRINT) clean
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
	make -C $(LIBA) fclean
	make -C $(PRINT) fclean
re : fclean all

.PHONY: all clean fclean re
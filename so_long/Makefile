CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = so_long.c get_next_line.c get_next_line_utils.c parsing.c validation.c\
	dfs.c control.c prt_map.c
OBJ = $(SRC:.c=.o)
NAME = so_long
MLX = ./mlx
MLXA = libmlx.a
MLXH = mlx.h
LIBF = ./Libft
LIBFF = libft.a
HEAD = so_long.h

all: ${NAME}

${NAME} : $(OBJ) $(HEAD)
	make -C $(MLX) 
	make -C $(LIBF)
	$(CC) $(FLAG) -I./ -Lmlx $(OBJ) -o $(NAME)  $(LIBF)/$(LIBFF) -lmlx -lXext -lX11 -lm

clean :
	rm -f $(OBJ)
	make -C $(MLX) clean
	make -C $(LIBF) clean
fclean : clean
	rm -f $(NAME)
	make -C $(LIBF) fclean
re : fclean all

.PHONY: all clean fclean re
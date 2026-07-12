CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = so_long.c get_next_line.c get_next_line_utils.c parsing.c validation.c\
	dfs.c control.c prt_map.c
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBA = ./mlx
LIBAA = libmlx.a
LIBF = ./Libft
LIBFF = libft.a
HEAD = so_long.h

all: ${NAME}

${NAME} : $(OBJ) $(HEAD)
	make -C $(LIBA) 
	make -C $(LIBF)
	$(CC) $(FLAG) -I./ -Lmlx $(OBJ) -o $(NAME)  $(LIBF)/$(LIBFF) -lmlx -lXext -lX11 -lm

clean :
	/bin/rm -f $(OBJ)
	make -C $(LIBA) clean
	make -C $(LIBF) clean
fclean : clean
	/bin/rm -f $(NAME)
	make -C $(LIBF) clean
re : fclean all

CC = cc
FLAG = -Werror -Wextra -Wall 
SRC = 
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBA = ./mlx
LIBAA = libmlx.a
LIBF = ./Libft
LIBFF = libft.a

all: ${NAME}

${NAME} : $(OBJ)
	make -C $(LIBA) 
	make -C $(LIBF)
	$(CC) $(FLAG) -I./ -Lmlx $(SRC) -o $(NAME)  $(LIBF)/$(LIBFF) -lmlx -lXext -lX11 -lm

clean :
	/bin/rm -f $(OBJ)
fclean : clean
	  /bin/rm -f $(NAME)
re : fclean all

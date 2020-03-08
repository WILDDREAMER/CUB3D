NAME	=	cub3D
SRC		=	*.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)
$(NAME) :
		gcc  -Wall -Wextra $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean	:
		rm -f *.o
fclean	: clean
		rm -f $(NAME)
re		: fclean
		make all
bonus	: re

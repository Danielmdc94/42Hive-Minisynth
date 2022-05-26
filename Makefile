NAME = minisynth

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/ -I/Users/dpalacio/.brew/include/SDL2 -D_THREAD_SAFE
# -I /usr/local/include 
LIB = -L ./libft -lft  -L/Users/dpalacio/.brew/lib -lSDL2 
#-L /usr/local/lib/ -lmlx
#FW = -framework OpenGL -framework AppKit

SRC = main.c read_file.c build_notes.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(INCLUDES) $(SRC) $(LIB) -o $(NAME) -flto

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re

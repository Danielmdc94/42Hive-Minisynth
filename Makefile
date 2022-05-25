NAME = minisynth

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I/Users/dpalacio/.brew/include/SDL2 -D_THREAD_SAFE
#-I ./libft/ -I /usr/local/include 
LIB =  -L/Users/dpalacio/.brew/lib -lSDL2 
#-L ./libft -lft -L /usr/local/lib/ -lmlx
#FW = -framework OpenGL -framework AppKit

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
#@make -C libft/ re
$(NAME):
	
	$(CC) $(INCLUDES) $(SRC) $(LIB) -o $(NAME) -flto
#@make -C libft/ clean
clean:
	
	/bin/rm -f $(OBJ)
#@make -C libft/ fclean
fclean: clean
	
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re

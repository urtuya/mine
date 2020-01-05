SRC = src/main.c src/init.c src/draw.c src/iso.c src/hooks.c src/rotation.c src/perspective.c src/put_pixel.c src/init2.c src/error.c src/color.c
OBJ = main.o init.o draw.o iso.o hooks.o rotation.o perspective.o put_pixel.o init2.o error.o
FLAG = -Wall -Wextra -Werror
TOOL = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
NAME = fdf
all: $(NAME)
	
$(NAME):
	make all -C libft
	gcc -g -I include/ $(SRC) $(TOOL) libft/libft.a -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all

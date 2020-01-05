# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vellery- <vellery-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 00:08:54 by oargrave          #+#    #+#              #
#    Updated: 2019/10/28 01:58:02 by vellery-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/main.c src/init.c src/draw.c src/iso.c src/hooks.c src/rotation.c\
		src/perspective.c src/put_pixel.c src/init2.c src/error.c
FLAG = -Wall -Wextra -Werror
TOOL = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
	
$(NAME):
	make all -C libft
	gcc $(FLAG) -I include/ $(SRC) $(TOOL) libft/libft.a -o $(NAME)

clean:
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	
re: fclean all

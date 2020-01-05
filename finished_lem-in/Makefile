# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 17:12:31 by ydavis            #+#    #+#              #
#    Updated: 2019/10/27 23:15:29 by ydavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC = backtrack.c checks.c cycle.c dijkstra.c flow.c free.c free_lemin.c\
	  get_node.c init_ants.c init_edges.c init_lemin.c init_node.c main.c\
	  misc.c new_path.c print.c read.c utils.c step.c realloc.c help.c
LIBFT = libft/libft.a
HDR = main.h

all: $(NAME)

$(NAME): libft $(SRC) $(HDR)
	@gcc -o $(NAME) $(SRC) $(LIBFT) -Wall -Wextra -Werror

libft:
	@make -C libft

clean:
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all, re, clean, fclean, libft

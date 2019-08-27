NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = adding_to_buf.c ft_printf.c intmax_toa.c print_d.c print_unsign.c set_all_fields.c \
		set_len_type.c uintmax_toa.c print_o_x_b.c print_char.c print_p.c print_f.c helping.c \
		color.c unsigned_addchar.c
INC = ft_printf.h
OFILE = $(SRC:.c=.o)
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I $(INC)
	make -C libft/ libft.a
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)
	
clean:
	rm -rf *.o
	rm -rf libft/libft.a
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	rm -rf *.gch
	make -C libft/ fclean

re: fclean all

.PHONY: all, clean, fclean, re

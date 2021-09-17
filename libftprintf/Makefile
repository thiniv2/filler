# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 12:56:34 by thinguye          #+#    #+#              #
#    Updated: 2021/09/17 12:56:34 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/ft_printf.c \
	srcs/scan_tags.c \
	srcs/print_d.c \
	srcs/set_tags_and_print.c \
	srcs/get_next_line.c

OBJ = ft_printf.o \
	scan_tags.o \
	print_d.o \
	set_tags_and_print.o \
	get_next_line.o

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	@ make -C libft/ fclean && make -C libft/
	@ cp $(LIBFT) $(NAME)
	@ gcc -Wall -Wextra -Werror -c $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "libftprintf.a done"

clean:
	@ /bin/rm -f *.o
	@ make -C libft/ clean
	@ echo "printf: object files removed"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C libft/ fclean
	@ /bin/rm -f a.out

re: fclean all

run: $(NAME)
	@ gcc $(NAME) main.c
	@ /bin/rm -f *.o
	@ make -C libft/ clean
	@ ./a.out

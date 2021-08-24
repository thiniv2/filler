# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 08:56:50 by thinguye          #+#    #+#              #
#    Updated: 2021/08/24 14:38:30 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = thinguye.filler

INC = includes/filler.h

LIB = ft_printf/libftprintf.a ft_printf/libft/libft.a

SRC = src/main.c \
		src/get_map.c

all: $(FILE)

$(FILE):
	@ echo "Compiling Filler..."
	@ make -C ft_printf
	@ make -C ft_printf clean
	@ gcc $(INC) -o $(FILE) $(SRC) $(LIB)
	@ echo "done"

clean:
	@ echo "Cleaning directories"
	@ make -C ft_printf clean
	@ echo "done"

fclean: clean
	@ echo "full cleaning directories"
	@ make -C ft_printf fclean
	@ rm -rf $(FILE)
	@ echo "done"

re: fclean all

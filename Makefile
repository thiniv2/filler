# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 08:56:50 by thinguye          #+#    #+#              #
#    Updated: 2021/09/15 16:51:31 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = thinguye.filler

INC = includes/filler.h

LIB = libftprintf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
		src/read_output.c \
		src/get_positions.c \
		src/reach_enemy.c \
		src/count_contacts.c \
		src/most_enemy.c \
		src/place_piece.c \
		src/check_fit.c \
		src/read_piece.c

all: $(FILE)

$(FILE):
	@ make -C libftprintf/ re
	@ gcc $(FLAGS) -o thinguye.filler $(SRC) $(LIB)
	@ echo "make done"

clean:
	@ echo "Cleaning directories"
	@ make -C libftprintf/ clean
	@ echo "done"

fclean: clean
	@ echo "full cleaning directories"
	@ make -C libftprintf/ fclean
	@ rm -rf $(FILE)
	@ echo "done"

re: fclean all

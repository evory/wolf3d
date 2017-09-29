# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 15:51:08 by bbrandt           #+#    #+#              #
#    Updated: 2017/09/29 03:34:04 by bbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = 	srcs/main.c \
		srcs/parser.c \
		srcs/tools.c \
		srcs/hooks.c \
		srcs/launcher.c \


FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/libft
	gcc $(FLAGS) -L lib/libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@echo "wolf3d done"

clean:
	make clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

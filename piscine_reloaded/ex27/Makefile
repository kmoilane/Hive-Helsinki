# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 17:12:23 by kmoilane          #+#    #+#              #
#    Updated: 2019/10/14 17:49:07 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/main.c srcs/ft_display_file.c

HEAD = includes/

OBJ = ft_display_file.o main.o ft_putchar.o ft_putstr.o

FLAGS = -Wall -Werror -Wextra -I$(HEAD)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

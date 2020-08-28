# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:05:12 by kmoilane          #+#    #+#              #
#    Updated: 2020/02/17 15:26:04 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = libft/ -I /usr/local/include -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS = *.c

OBJS = *.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	make -C libft/ clean
	gcc $(FLAGS) -c $(SRCS)
	gcc -o $(NAME) $(OBJS) -I $(INC)
	chmod +x $(NAME)

.PHONY: clean fclean re fresh

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME) libft/*.a

re: fclean all

fresh: re
	/bin/rm -f $(OBJS)


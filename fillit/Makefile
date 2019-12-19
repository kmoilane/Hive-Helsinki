# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 18:32:31 by kmoilane          #+#    #+#              #
#    Updated: 2019/12/17 17:44:21 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c solver.c map_maker.c piecemaker.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = libft/ -L libft/ -lft

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

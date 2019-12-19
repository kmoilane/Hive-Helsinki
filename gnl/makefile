# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 15:31:48 by kmoilane          #+#    #+#              #
#    Updated: 2019/11/25 16:11:39 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

OBJS = *.o

all: $(NAME)
	
$(NAME):	
		clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
		clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

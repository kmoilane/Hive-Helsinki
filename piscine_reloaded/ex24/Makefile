# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 16:44:07 by kmoilane          #+#    #+#              #
#    Updated: 2019/10/14 17:59:50 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
	   srcs/ft_strlen.c srcs/ft_swap.c

HEAD = includes/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I$(HEAD)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

NAME =  libftprintf.a

EXE = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT_FOLDER = ./libft/

LIB = ./libft/libft.a

LIB_OBJ = ./libft/*.o

SRCS1 = ./srcs/ft_printf.c ./srcs/conversions.c ./srcs/converters.c \
		./srcs/deal_conversions1.c ./srcs/deal_conversions2.c ./srcs/deal_conversions3.c \
		./srcs/dealint.c ./srcs/main.c ./srcs/mods.c ./srcs/swaps.c

SRCS2 = ./srcs/ft_printf.c ./srcs/conversions.c ./srcs/converters.c \
		./srcs/deal_conversions1.c ./srcs/deal_conversions2.c ./srcs/deal_conversions3.c \
		./srcs/dealint.c ./srcs/main.c ./srcs/mods.c ./srcs/swaps.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS1)))

OBJS2 = $(subst .c,.o,$(subst srcs/,,$(SRCS2)))

INCL = -I ./includes/ -I ./libft/includes/



all: $(NAME)

$(NAME): $(SRCS1)
	@make -s -C $(LIBFT_FOLDER)
	@cp $(LIB) ./$(NAME)
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS1)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	@rm -f $(OBJS) $(LIB_OBJ)
	@make -s clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C libft
	
re: fclean all

run: 
	@gcc -c $(SRCS2) $(INCL)
	@gcc $(INCL) $(OBJS2) $(LIB) -o $(EXE)
	
printf: clean run
		@rm -f $(OBJS2)
		@make -s clean -C libft

.PHONY: clean fclean re all

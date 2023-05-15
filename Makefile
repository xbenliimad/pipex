NAME= pipex

SRC= ./src/main.c

OBJ=$(SRC:%.c=%.o)

INCLUDES= -I./includes -I./utils/libft -I./utils/get-next-line -I./utils/ft_printf

FLAGS= -Wall -Wextra -Werror -fsanitize=address $(INCLUDES)

CC= cc

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -o $@

./utils/libft/libft.a :
	make -C ./utils/libft  bonus


./utils/ft_printf/libftprintf.a :
	make -C ./utils/ft_printf

./utils/get-next-line/get_next_line.a :
	make -C ./utils/get-next-line


clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C ./utils/libft clean
	make -C ./utils/ft_printf clean
	make -C ./utils/get-next-line clean

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C ./utils/libft fclean
	make -C ./utils/ft_printf fclean
	make -C ./utils/get-next-line fclean

re : fclean all


.PHONY : all fclean clean re
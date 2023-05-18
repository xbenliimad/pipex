NAME= pipex

SRC= ./src/main.c \
./src/get_final_path.c \
./src/utils.c\
./src/child_process.c

SRC_BONUS= ./bonus/main_bonus.c \
./bonus/get_final_path_bonus.c \
./bonus/utils_bonus.c\
./bonus/child_process_bonus.c

OBJ=$(SRC:%.c=%.o)

OBJ_BONUS=$(SRC_BONUS:%.c=%.o)

INCLUDES= -I./includes -I./utils/libft -I./utils/get-next-line -I./utils/ft_printf

FLAGS= -Wall -Wextra -Werror -fsanitize=address $(INCLUDES)

CC= cc

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -o $@

bonus : $(OBJ_BONUS) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -o pipex

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
SRC= get_next_line.c	get_next_line_utils.c \

OBJ= $(SRC:.c=.o)

FLAGS= -Wall -Wextra -Werror

CC= cc

NAME= get_next_line.a

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean clean re
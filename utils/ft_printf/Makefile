NAME = libftprintf.a

SRC = ft_printf.c	ft_putchar.c	ft_putnbr.c ft_putstr.c\
		ft_putnbr_unsigned.c	ft_puthexa.c	ft_putadress.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
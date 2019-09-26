NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra -I./$(INC)
SRC_FILE = ft_buf.c ft_printf.c
SRC = srcs/
LIBFT = libft/
INC = includes/

OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re
all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -c $(SRC) -L -lft
	ar rc 
NAME = libftprintf.a
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LFT_PATH = ./libft/
INC_PATH = ./includes/
FLAGS = -Wall -Werror -Wextra -g

INC = $(addprefix -I, $(INC_PATH))

SRC_NAME = ft_buf.c\
		ft_printf.c\
		parse_param.c\
		dis_proc_fin.c\
		printcs.c\
		printdiouxb.c\
		printfeg.c\
		printk.c\
		printp.c\
		printf_f.c\
		printf_helper.c\
		printe.c\
		arg_list.c\
		arg_lst_util.c\
		spec_util.c\
		get_param.c\
        arb_add_sub.c\
        arb_mult_div.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LFT_SRC_NAME = ft_atoi.c\
		ft_err_exit.c\
        ft_isascii.c\
        ft_memchr.c\
        ft_memset.c\
        ft_strcpy.c\
        ft_strncat.c\
        ft_strrchr.c\
        ft_bzero.c\
        ft_isdigit.c\
        ft_memcmp.c\
        ft_strcat.c\
        ft_strdup.c\
        ft_strncmp.c\
        ft_strstr.c\
        ft_isalnum.c\
        ft_isprint.c\
        ft_memcpy.c\
        ft_strchr.c\
        ft_strlcat.c\
        ft_strncpy.c\
        ft_tolower.c\
        ft_isalpha.c\
        ft_memccpy.c\
        ft_memmove.c\
        ft_strcmp.c\
        ft_strlen.c\
        ft_strnstr.c\
        ft_toupper.c\
        ft_memalloc.c\
        ft_memdel.c\
        ft_strnew.c\
        ft_strdel.c\
        ft_strclr.c\
        ft_striter.c\
        ft_striteri.c\
        ft_strmap.c\
        ft_strmapi.c\
        ft_strequ.c\
        ft_strnequ.c\
        ft_strsub.c\
        ft_strjoin.c\
        ft_strtrim.c\
        ft_strsplit.c\
        ft_itoa.c\
        ft_putchar.c\
        ft_putstr.c\
        ft_putendl.c\
        ft_putnbr.c\
        ft_putchar_fd.c\
        ft_putstr_fd.c\
        ft_putendl_fd.c\
        ft_putnbr_fd.c\
        ft_lstadd.c\
        ft_lstdel.c\
        ft_lstdelone.c\
        ft_lstiter.c\
        ft_lstmap.c\
        ft_lstnew.c\
		ft_lstadd_bk.c\
		ft_lstinsert.c\
		ft_lstdelat.c\
		ft_lstlen.c\
		ft_lstat.c\
		ft_ulltoa_base.c\
		ft_lltoa_base.c\
		ft_strup.c\
        ft_stradd.c\
		ft_strtrimc.c
LFT_OBJ_NAME = $(LFT_SRC_NAME:.c=.o)
LFT_SRC = $(addprefix $(LFT_PATH), $(LFT_SRC_NAME))
LFT_OBJ = $(addprefix $(LFT_PATH), $(LFT_OBJ_NAME))

.PHONY = all clean fclean re

all: $(NAME)

test: re
	@gcc test.c -L. -lftprintf $(LFT_SRC) $(INC) -g
	@echo "Test executive established"

$(NAME):
	@make $(LFT_OBJ)
	@echo "libft files compiled"
	@make $(OBJ)
	@echo "ft_printf files compiled"
	@ar rc $(NAME) $(OBJ) $(LFT_OBJ)
	@ranlib $(NAME)
	@echo "library established"

$(LFT_OBJ_PATH)%.o: $(LFT_SRC_PATH)%.c
	@gcc $(FLAGS) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(LFT_OBJ)
	@/bin/rm -rf $(OBJ_PATH)
	@echo "cleaned all object files"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf a.out.dSYM
	@/bin/rm -f a.out
	@echo "deleted library file"

re: fclean all

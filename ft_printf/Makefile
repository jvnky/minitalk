NAME=libftprintf.a

SRCS = src/ft_printf.c \
		tools/format_nbr.c 	 \
		tools/format_str.c 	 \
		tools/format_x.c	 \
		tools/ft_putnbr.c 	\
		tools/ft_put_unbr.c 	\
		tools/format_c.c 	\
		tools/format_p.c \
		tools/format_u.c \
		tools/ft_putchar.c \
		tools/ft_putstr.c \
		tools/check_type.c \

OBJ = ft_printf.o \
		check_type.o	\
		format_nbr.o 	 \
		format_str.o 	 \
		format_x.o	 \
		ft_putnbr.o 	\
		ft_put_unbr.o 	\
		format_c.o 	\
		format_p.o \
		format_u.o \
		ft_putchar.o \
		ft_putstr.o \

CC_FLAG = -Wall -Wextra -Werror

INCLUDES = src/ft_printf.h 	\
		tools/tools.h	\

$(NAME): $(OBJ)

$(OBJ): $(SRCS)$(INCLUDES)
	@printf Compilate
	@gcc $(CC_FLAG) -c $(SRCS)
	@ar rcs $(NAME) $(OBJ) 	
all: $(NAME)

bonus: all
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychair <ychair@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 05:42:12 by ychair            #+#    #+#              #
#    Updated: 2021/12/22 05:42:12 by ychair           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
.PHONY	:	all clean fclean re

NAME_SERVER	=	server
NAME_CLIENT	=	client

HEADER		=   minitalk.h

SRC_SERVER	=	server.c
SRC_CLIENT	=   client.c

FLAGS		=	-Wall -Wextra -Werror

OBJ_SERVER	=	$(patsubst %.c, %.o, $(SRC_SERVER))
OBJ_CLIENT	=	$(patsubst %.c, %.o, $(SRC_CLIENT))

all		: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(SRC_SERVER) $(HEADER)
	gcc $(FLAGS) -c $(SRC_SERVER)
	gcc $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(SRC_CLIENT) $(HEADER)
	gcc $(FLAGS) -c $(SRC_CLIENT)
	gcc $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

clean	:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean	:	clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re		:	fclean all
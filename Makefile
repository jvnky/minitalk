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
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC_SERVER = server.c
SRC_CLIENT = client.c
RM = rm -f

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME): all
	$(CC) -g $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)
	$(CC) -g $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)
	
clean:
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		
fclean: clean

re: fclean all
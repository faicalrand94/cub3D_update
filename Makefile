# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 13:09:22 by fbouibao          #+#    #+#              #
#    Updated: 2020/12/26 19:05:06 by fbouibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror 

SEARCH_PATH = -I /usr/local/include

LIB = -L /usr/local/lib -lmlx

CUBFLAGS = -framework appkit -framework opengl -g

SRC =  *.c cub/*.c cub/get_next_line/*.c ft_printf/*.c

CC = gcc

OBJECTS = $(SRC:.c=.o)

# OBJECTS_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME):
		@$(CC) $(SEARCH_PATH) $(SRC) $(FLAGS) $(LIB) $(CUBFLAGS) -o $(NAME)


# bonus: $(SRC_B)
# 				 @gcc $(FLAGS) -c $(SRC_B)
# 				 @ar rc $(NAME) $(OBJECTS_B)
# 				 @ranlib $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

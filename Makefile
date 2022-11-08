# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbally <lbally@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 18:25:52 by lbally            #+#    #+#              #
#    Updated: 2022/11/03 19:04:52 by lbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

SRC = gnl/gnl.c \
	  gnl/gnlu.c \
	  parse.c \
	  parse2.c \
	  main.c \
	  quit.c \
	  draw.c \
	  remplace.c \
	  touche.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o : %.c
		$(CC) -o $@ -c $< $(CFLAGS)

$(NAME) 	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

all : $(NAME)

clean :
		$(RM) $(OBJ) *.gch

fclean : clean
		$(RM) $(NAME) cub3d

re : fclean all

.PHONY : all clean fclean re
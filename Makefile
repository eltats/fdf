# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 15:36:26 by hcloves           #+#    #+#              #
#    Updated: 2020/02/23 23:51:40 by hcloves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c interface.c parse.c utils.c draw_x.c draw_y.c key.c utils2.c \
		control.c

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra
FDEBUG = -g

OBJ = $(SRC:.c=.o)

# lib
LIBFT = libft/libft.a

# fraimwork
MLXFRAIMWORK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIBFRAIMWORK = -L ./libft -lft 

HEADER = 

all: $(NAME)

%.o: %.c
	$(CC) -c -I ./libft -I ./minilibx_macos $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(MLXFRAIMWORK) $(LIBFRAIMWORK) -o $(NAME)

clean:
	/bin/rm -f $(OBJ) -silent
	make -C libft clean -silent

fclean: clean
	/bin/rm -f $(NAME) -silent
	make -C libft fclean -silent

re: fclean all

.PHONY: clean fclean re
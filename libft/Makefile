# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 19:24:46 by wkraig            #+#    #+#              #
#    Updated: 2019/10/15 20:25:26 by wkraig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h

FILES = ft_atoi.c ft_putchar.c ft_strlen.c \
        ft_putnbr.c ft_putstr.c ft_strcpy.c \
        ft_strdup.c ft_memset.c ft_bzero.c \
        ft_strncpy.c ft_strcat.c ft_strncat.c \
        ft_strlcat.c ft_strchr.c ft_memcmp.c \
        ft_memchr.c ft_memmove.c ft_memccpy.c \
        ft_memcpy.c \
        ft_strrchr.c ft_strstr.c ft_strnstr.c \
        ft_strcmp.c ft_strncmp.c ft_isalpha.c \
        ft_isdigit.c ft_isalnum.c ft_isascii.c \
        ft_isprint.c ft_tolower.c ft_toupper.c \
        ft_memalloc.c ft_memdel.c ft_strnew.c \
        ft_strdel.c ft_strclr.c ft_striter.c \
        ft_striteri.c ft_strmap.c ft_strmapi.c \
        ft_strequ.c ft_strnequ.c ft_strsub.c \
        ft_strjoin.c ft_strtrim.c ft_strsplit.c \
        ft_itoa.c ft_putendl.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
        ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
        ft_lstiter.c ft_lstmap.c ft_words.c ft_strcreate.c \
        ft_checkf.c ft_numbers.c ft_isspace.c get_next_line.c \
        ft_sqrt.c

OBJS = $(FILES:.c=.o)
  
all: $(NAME)

%.o: %.c $(HDR)
	@gcc -c -Wall -Wextra -Werror $< -I $(HDR)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME) 

clean:
	@rm -f $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)


re: fclean all
 	

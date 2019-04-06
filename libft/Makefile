# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 20:23:35 by jcrisp            #+#    #+#              #
#    Updated: 2018/10/21 16:02:35 by jcrisp           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
FILES = ./*.c
OBJ = $(FILES:%.c=%.o)

$(NAME): 
		$(CC) $(CFLAGS) -c $(FILES) -I libft.h
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

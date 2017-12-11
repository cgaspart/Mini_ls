# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:11:37 by cgaspart          #+#    #+#              #
#    Updated: 2017/12/11 13:38:04 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = main.c

all: $(NAME)

$(NAME): $(LIB)
	gcc -o $(NAME) $(FLAG) $(SRC) -L./libft -lft

$(LIB):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

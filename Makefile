# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 12:13:09 by pcrosnie          #+#    #+#              #
#    Updated: 2016/02/02 13:55:37 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -L /usr/lib -lmlx -framework OpenGl -framework AppKit

SRC = get_next_line.c libft.a ft_read.c main.c ft_loop.c ft_connect.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean:
	
fclean:
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

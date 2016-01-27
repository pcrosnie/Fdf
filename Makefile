# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 12:13:09 by pcrosnie          #+#    #+#              #
#    Updated: 2016/01/25 14:51:55 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -L /usr/lib -lmlx -framework OpenGl -framework AppKit

SRC = get_next_line.c libft.a ft_read.c main.c ft_display.c ft_connect_points.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean:
	
fclean:
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/30 14:40:59 by dskittri          #+#    #+#             #
#   Updated: 2020/12/30 15:03:19 by dskittri         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

SOURCES = *.c

NAME = philo_three

HEADER = philo_3.h

all: $(NAME)

$(NAME): $(SOURCES) $(HEADER)
	gcc -Wall -Wextra -Werror $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

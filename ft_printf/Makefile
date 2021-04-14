# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/04/30 14:40:59 by dskittri          #+#    #+#             #
#   Updated: 2020/06/30 15:03:19 by dskittri         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME=libftprintf.a

SOURCES=ft_printf.c \
	parser.c \
	printf_string.c \
	printf_int.c \
	printf_unsig.c \
	printf_hex.c \
	printf_pointer.c \
	printf_char.c \
	printf_utils_1.c \
	printf_utils_2.c \
	ft_write.c \
	ft_atoi.c \
	ft_len.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = printf.h

all: $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $<
	
$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
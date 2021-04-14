# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/04/30 14:40:59 by dskittri          #+#    #+#             #
#   Updated: 2020/04/30 15:03:19 by dskittri         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME=libft.a

SOURCES=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isdigit.c ft_isprint.c ft_isascii.c \
	ft_itoa.c ft_strmapi.c ft_strncmp.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_strnstr.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_substr.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_split.c ft_calloc.c ft_strlcpy.c ft_strrchr.c 

OBJECTS = $(SOURCES:.c=.o)

HEADER = libft.h

all: $(NAME)

$(OBJECTS): $(SOURCES) $(HEADER) 
	gcc -Wall -Wextra -Werror -c $(SOURCES) -I $(HEADER)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
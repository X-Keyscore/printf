# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 06:11:05 by anraymon          #+#    #+#              #
#    Updated: 2023/11/17 15:54:30 by anraymon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libftprintf.a

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS   = ft_printf.c \
				includes/ft_print_char.c \
				includes/ft_print_hex.c \
				includes/ft_print_int.c \
				includes/ft_print_ptr.c \
				includes/ft_print_str.c \
				includes/ft_print_uint.c \
				includes/ft_convert_base.c \
				includes/ft_strlen.c \

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

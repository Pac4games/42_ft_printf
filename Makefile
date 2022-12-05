# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 12:11:31 by paugonca          #+#    #+#              #
#    Updated: 2022/12/05 17:27:42 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf num_and_mem_utils \
libft/ft_itoa libft/ft_putchar libft/ft_putstr libft/ft_strlen	

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME) : $(SRC:=.o)
	ar rc $(NAME) $(SRC:=.o)

clean:
	$(RM) $(SRC=.o)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re

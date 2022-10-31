# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 12:23:31 by paugonca          #+#    #+#              #
#    Updated: 2022/10/31 14:33:14 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strlen ft_toupper ft_tolower ft_strdup ft_itoa_base\
ft_memcpy

CC = gcc
RM = rm -f
CCFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM) $(SRC:=.o)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 20:32:23 by mel-bouh          #+#    #+#              #
#    Updated: 2024/01/05 11:12:46 by mel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_format.c ft_putchar.c \
		ft_putnbr.c ft_putstr.c
OBJT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJT)
	@ar rcs $(NAME) $?
%.o: %.c
	@cc $(FLAGS) -c $?
clean:
	@rm -rf $(OBJT)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re

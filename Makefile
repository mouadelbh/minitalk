# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 21:30:38 by mel-bouh          #+#    #+#              #
#    Updated: 2024/01/05 16:20:42 by mel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRVNAME = server
LIB = libftprintf.a
PATH = ./ft_printf/$(LIB)
CLINAME = client

all: $(SRVNAME)

$(SRVNAME): $(CLINAME) server.c
	cc $(FLAGS) $(PRINT) server.c utils.c $(PATH) -o $(SRVNAME)
$(CLINAME): client.c
	cc $(FLAGS) $(PRINT) client.c utils.c $(PATH) -o $(CLINAME)
fclean:
	rm -rf server client
re: fclean all

.PHONY: all fclean re

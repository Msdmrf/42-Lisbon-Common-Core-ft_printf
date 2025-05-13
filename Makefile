# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 12:14:15 by migusant          #+#    #+#              #
#    Updated: 2025/05/13 13:34:08 by migusant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = ft_printf.c ft_printf_utils.c ft_printf_hex.c

OFILES = $(CFILES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(FLAGS) -c $^
	$(AR) $(NAME) $(OFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
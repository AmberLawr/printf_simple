
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 12:47:57 by jzhou             #+#    #+#              #
#    Updated: 2021/06/22 12:47:57 by jzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c add_functions1.c add_functions2.c \

LIBFT_PATH = ./libft/

MAKE = make

all: sub_libft $(NAME)


$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) *.o $(LIBFT_PATH)*.o

sub_libft:
	$(MAKE) libft.a -C $(LIBFT_PATH)

clean:
	rm -f *.out
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

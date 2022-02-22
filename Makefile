# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:50:08 by donghshi          #+#    #+#              #
#    Updated: 2022/02/22 11:52:24 by donghshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
OBJS = $(SRCS:.c=.o)
SRCS = ft_atoi.c math.c fileio.c std.c my_print.c matrix.c solving.c main.c

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

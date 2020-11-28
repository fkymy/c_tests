# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufukuya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 18:59:19 by yufukuya          #+#    #+#              #
#    Updated: 2020/11/28 12:42:16 by yufukuya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a

includes := .
SRCS := srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_read.s \
		srcs/ft_write.s \
		srcs/ft_strdup.s \

OBJS := $(SRCS:.s=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

$(OBJS): %.o: %.s
	nasm -f macho64 $< -o $@

.PHONY: .re fclean clean test
re: fclean all
fclean: clean ; -rm -f $(NAME)
clean: ; rm -rf srcs/*.o

test:
	gcc -Wall -Werror -Wextra -L. main.c -lasm -fsanitize=address

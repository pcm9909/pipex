# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 03:16:13 by chunpark          #+#    #+#              #
#    Updated: 2024/04/08 03:16:13 by chunpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADR = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS =	ft_memcpy.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_substr.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADR)
			@ar rcs $(NAME) $(OBJS)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJS)

fclean: clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

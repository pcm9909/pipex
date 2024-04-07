# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 03:15:38 by chunpark          #+#    #+#              #
#    Updated: 2024/04/08 03:15:40 by chunpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
DIR = ./mandatory
SRC = errmsg.c execve.c make_cmd.c pipex.c
SRCS = $(addprefix $(DIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)

BONUS = pipex_bonus
BONUS_DIR = ./bonus
BONUS_SRC = errmsg_bonus.c execute_bonus.c here_doc_bonus.c make_cmd_bonus.c pipex_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRC))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
			@clear
			@echo ""
			@echo "           [mandatory]            "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make re -C ./utils/libft
			@echo "@                              @"
			@echo "@         \033[32mHello libft.a\033[0m        @"
			@$(CC) $(CFLAGS) $(OBJS) ./utils/libft/libft.a -o $(NAME)
			@echo "@          \033[32mHello pipex\033[0m         @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
			@clear
			@echo ""
			@echo "             [bonus]              "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@echo "@                              @"
			@make re -C ./utils/libft
			@echo "@         \033[32mHello libft.a\033[0m        @"
			@make re -C ./utils/get_next_line
			@echo "@     \033[32mHello get_next_line.a\033[0m    @"
			@$(CC) $(CFLAGS) $(BONUS_OBJS) ./utils/libft/libft.a ./utils/get_next_line/get_next_line.a  -o $(BONUS)
			@echo "@       \033[32mHello pipex_bonus\033[0m      @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2

clean:		
			@clear
			@echo ""
			@echo "             [clean]              "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make clean -C ./utils/libft
			@echo "@                              @"
			@echo "@        \033[31mGoodbye libft.o\033[0m       @"
			@make clean -C ./utils/get_next_line
			@echo "@    \033[31mGoodbye get_next_line.o\033[0m   @"
			@rm -f $(OBJS) $(BONUS_OBJS)
			@echo "@       \033[31mGoodbye pipex.o\033[0m        @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2

fclean: clean
			@clear
			@echo ""
			@echo "             [fclean]             "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make fclean -C ./utils/libft
			@echo "@                              @"
			@echo "@        \033[31mGoodbye libft.a\033[0m       @"
			@make fclean -C ./utils/get_next_line
			@echo "@    \033[31mGoodbye get_next_line.a\033[0m   @"
			@rm -f $(NAME) $(BONUS)
			@echo "@         \033[31mGoodbye pipex\033[0m        @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
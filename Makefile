# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 03:15:38 by chunpark          #+#    #+#              #
#    Updated: 2024/04/09 19:22:11 by chunpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

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

all: print $(NAME)

$(NAME): $(OBJS)
			@clear
			@echo ""
			@echo "          [ mandatory ]            "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make re -C ./utils/libft > /dev/null
			@echo "@                              @"
			@echo "@         \033[32mHello libft.a\033[0m        @"
			@$(CC) $(CFLAGS) $(OBJS) ./utils/libft/libft.a -o $(NAME)
			@echo "@          \033[32mHello pipex\033[0m         @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

bonus: print $(BONUS)

$(BONUS): $(BONUS_OBJS)
			@clear
			@echo ""
			@echo "            [ bonus ]           "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@echo "@                              @"
			@make re -C ./utils/libft > /dev/null
			@echo "@         \033[32mHello libft.a\033[0m        @"
			@make re -C ./utils/get_next_line > /dev/null
			@echo "@     \033[32mHello get_next_line.a\033[0m    @"
			@$(CC) $(CFLAGS) $(BONUS_OBJS) ./utils/libft/libft.a ./utils/get_next_line/get_next_line.a  -o $(BONUS)
			@echo "@       \033[32mHello pipex_bonus\033[0m      @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"


clean:		
			@clear
			@echo ""
			@echo "            [ clean ]              "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make clean -C ./utils/libft > /dev/null
			@echo "@                              @"
			@echo "@        \033[31mGoodbye libft.o\033[0m       @"
			@make clean -C ./utils/get_next_line > /dev/null
			@echo "@    \033[31mGoodbye get_next_line.o\033[0m   @"
			@rm -f $(OBJS) $(BONUS_OBJS)
			@echo "@       \033[31mGoodbye pipex.o\033[0m        @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2
			@clear

fclean: clean
			@clear
			@echo ""
			@echo "            [ fclean ]             "
			@echo ""
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@make fclean -C ./utils/libft > /dev/null
			@echo "@                              @"
			@echo "@        \033[31mGoodbye libft.a\033[0m       @"
			@make fclean -C ./utils/get_next_line > /dev/null
			@echo "@    \033[31mGoodbye get_next_line.a\033[0m   @"
			@rm -f $(NAME) $(BONUS)
			@echo "@         \033[31mGoodbye pipex\033[0m        @"
			@echo "@                              @"
			@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
			@sleep 2
			@clear

re: fclean all

re_bonus: fclean bonus

print:
			@clear
			@echo "\033[35m♪┏(・o･)┛♪\033[0m"
			@sleep 0.5
			@clear
			@echo "\033[1;33m♪┗(・o･)┓♪\033[0m"
			@sleep 0.5
			@clear
			@echo "\033[35m♪┏(・o･)┛♪\033[0m"
			@sleep 0.5
			@clear
			@echo "\033[1;33m♪┗(・o･)┓♪\033[0m"
			@sleep 0.5
			@clear


		
.PHONY: all bonus clean fclean re re_bonus print

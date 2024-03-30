NAME = pipex

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS =	pipex.c \
        check.c \
        make_cmd.c \
        execve.c 

LIBFT_SRCS =	ft_split.c \
                ft_strjoin.c \
                ft_strlcat.c \
                ft_strlcpy.c \
                ft_strlen.c \
                ft_strncmp.c \
                ft_substr.c \
                ft_strdup.c \
                ft_memcpy.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

HEADER = pipex.h

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_OBJS) $(HEADER)
			@echo "\nCompiling $(NAME)..."
			@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIBFT_OBJS)
			@echo "$(NAME) compiled!\n"

%.o : %.c
			@echo "Compiling $<..."
			@$(CC) $(CCFLAGS) -c $< -o $@
			@echo "$< compiled!"

clean : 
			@echo "Removing object files..."
			@rm -f $(OBJS) $(LIBFT_OBJS)
			@echo "Object files removed!\n"


fclean : clean
			@echo "Removing $(NAME)..."
			@rm -f $(NAME)
			 @echo "$(NAME) removed!\n"

re : fclean all
			@echo "Recompilation completed!"

.PHONY : all clean fclean re print
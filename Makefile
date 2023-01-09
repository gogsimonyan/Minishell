UNAME = $(shell uname -s)

NAME = minishell

CC	=	gcc

SRCS =	$(wildcard src/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

FLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

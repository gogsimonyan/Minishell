UNAME = $(shell uname -s)

NAME = minishell

SRCS =	$(wildcard src/*/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

LINK = -lreadline

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINK) -o $(NAME)

clean:
	$(RM) $(OBJS) src/*.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 

SRCS = main.c $(wildcard pars_utils/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
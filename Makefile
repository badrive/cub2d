NAME = cub3d

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 

SRCS = main.c $(wildcard pars_utils/*.c)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
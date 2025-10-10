NAME = cub
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

MAIN_SRCS = main.c init_free.c

GNL_SRCS = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

PARS_SRCS = pars_utils/anti_leaks.c \
            pars_utils/check_map.c \
            pars_utils/ft_check_elm.c \
            pars_utils/ft_check_rgb.c \
            pars_utils/ft_dup_color.c \
            pars_utils/ft_dup_path.c \
            pars_utils/load_map_utils.c \
            pars_utils/parsing.c \
            pars_utils/utils1.c \
            pars_utils/utils2.c \
            pars_utils/utils3.c

RAY_SRCS = ray_castin/hook.c \
           ray_castin/mouvs.c \
           ray_castin/raycasting.c \
           ray_castin/texters.c \
           ray_castin/utils.c

SRCS = $(MAIN_SRCS) $(GNL_SRCS) $(PARS_SRCS) $(RAY_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
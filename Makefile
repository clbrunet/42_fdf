NAME = fdf
NAME_BONUS = fdf_bonus

LIBMLX = minilibx-linux/libmlx.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux/
LDFLAGS = $(LIBMLX) -lXext -lX11 -lm

SRCS = src/ft.c \
			 src/ft2.c \
			 src/get_next_line_utils.c \
			 src/get_next_line.c \
			 src/angle.c \
			 src/vector2int.c \
			 src/vector2.c \
			 src/vector3.c \
			 src/mlx_img_put2.c \
			 src/mlx_img_put.c \
			 src/get_screen_points.c \
			 src/hooks.c \
			 src/initialize_mlx.c \
			 src/get_file_lines.c \
			 src/map.c \
			 src/tile.c \
			 src/main.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = src_bonus/ft_bonus.c \
						 src_bonus/ft2_bonus.c \
						 src_bonus/get_next_line_utils_bonus.c \
						 src_bonus/get_next_line_bonus.c \
						 src_bonus/angle_bonus.c \
						 src_bonus/vector2int_bonus.c \
						 src_bonus/vector2_bonus.c \
						 src_bonus/vector3_bonus.c \
						 src_bonus/mlx_img_put_bonus.c \
						 src_bonus/mlx_img_put2_bonus.c \
						 src_bonus/mlx_img_put3_bonus.c \
						 src_bonus/screen_points_bonus.c \
						 src_bonus/translate_bonus.c \
						 src_bonus/zoom_bonus.c \
						 src_bonus/hooks_bonus.c \
						 src_bonus/hooks2_bonus.c \
						 src_bonus/initialize_mlx_bonus.c \
						 src_bonus/get_file_lines_bonus.c \
						 src_bonus/map_bonus.c \
						 src_bonus/map2_bonus.c \
						 src_bonus/map3_bonus.c \
						 src_bonus/tile_bonus.c \
						 src_bonus/main_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(LIBMLX):
	make -C minilibx-linux/

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

bonus: $(LIBMLX) $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

clean_bonus:
	rm -f $(OBJS_BONUS)

clean_libs:
	make clean -C minilibx-linux/

fclean: clean
	rm -f $(NAME)

fclean_bonus: clean_bonus
	rm -f $(NAME_BONUS)

fclean_libs: clean_libs
	rm -f $(LIBMLX)

re: fclean all

re_bonus: fclean_bonus bonus

re_libs: fclean_libs $(LIBMLX)

.PHONY: all bonus clean clean_bonus clean_libs fclean fclean_bonus fclean_libs re re_bonus re_libs

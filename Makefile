NAME = fdf
LIBMLX = minilibx-linux/libmlx.a

CC = clang
CFLAGS = -Wall -Wextra -Werror						\
				 -I./minilibx-linux/ -I./include/
LDFLAGS = $(LIBMLX) -lXext -lX11 -lm

SRCS = src/write.c					\
			 src/angle.c					\
			 src/vector2int.c			\
			 src/vector2.c				\
			 src/vector3.c				\
			 src/mlx_img_put.c		\
			 src/hooks.c					\
			 src/initialize_mlx.c	\
			 src/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBMLX):
	make -C minilibx-linux/

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

bonus: $(NAME)

clean:
	rm -f $(OBJS)

clean_libs: clean
	make clean -C minilibx-linux/

fclean: clean
	rm -f $(NAME)

fclean_libs: fclean clean_libs
	rm -f $(LIBMLX)

re: fclean all

re_libs: fclean_libs all

.PHONY: all clean clean_libs fclean fclean_libs re re_libs bonus

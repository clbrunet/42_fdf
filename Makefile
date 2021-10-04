NAME = fdf
LIBMLX = minilibx-linux/libmlx.a

CC = clang
CFLAGS = -Wall -Wextra -Werror						\
				 -I./minilibx-linux/ -I./include/
LDFLAGS = $(LIBMLX) -lXext -lX11 -lm

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBMLX):
	make -C minilibx-linux/

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME)

clean:
	make clean -C minilibx-linux/
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

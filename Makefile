NAME = fractol

CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux/ -Imlx_linux -O3 -fsanitize=address

SRCS = main.c \
       init.c \
       math_utils.c \
       render.c \
       string_utils.c \
       get_color.c \
       events.c
	   
OBJS = $(SRCS:.c=.o)

# Reglas principales
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./minilibx-linux/libmlx_Linux.a -Lmlx_linux -I./minilibx-linux/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c fractol.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

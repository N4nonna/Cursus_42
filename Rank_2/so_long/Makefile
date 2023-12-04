NAME = so_long

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRCS= fdf.c map.c point.c limits.c hooks.c draw.c

OBJ= ${SRCS:%.c=%.o}

%.o:		%.c
			$(CC) $(CFLAGS) -I./libft/include -I./mlx_linux -c $? -o $@

all:		${NAME}

${NAME}:	$(OBJ)
			@make -C libft
			@make -C mlx_linux
			$(CC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			make clean -C libft
			make clean -C mlx_linux
			rm -f $(OBJ)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:	all bonus clean fclean re
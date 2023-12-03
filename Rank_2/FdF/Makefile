NAME = fdf

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRCS= mlx_test.c

OBJ= ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Ifdf.h -Ilibft -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		${NAME}

${NAME}:	$(OBJ)
			@make -C libft
			@make -C mlx_linux
			$(CC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			make clean -C libft
			make -C mlx_linux
			rm -f $(OBJ)

fclean:		clean
			rm -f ${NAME}: all

re:			fclean all

.PHONY:	all bonus clean fclean re
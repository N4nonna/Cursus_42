NAME = solong

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRC= mlx_test.c

OBJ= ${SRC:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		${NAME}

${NAME}:	$(OBJ)	
			$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f ${NAME}: all

re:			fclean all

.PHONY:	all bonus clean fclean re
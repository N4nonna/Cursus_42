NAME= libftprintf.a

INCLUDE= include
SRC_PATH= src
OBJ_PATH= obj
LIBFT= libft

CC= cc
CFLAGS= -Wall -Wextra -Werror -I

SRC_FILE= ft_printf.c\
	print_int.c\
	print_pointer.c\
	print_string.c

OBJ_FILE= ${SRC_FILE:.c=.o}
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILE))

AR= ar rcs
RM= rm -f

OBJF= .cache_exists

all:		${NAME}

${NAME}:	${OBJ}
			@make -C ${LIBFT}
			@cp libft/libft.a .
			@mv libft.a ${NAME}
			@${AR} ${NAME} ${OBJ}

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | ${OBJF}
			$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_PATH)

clean:
			@${RM} -rf ${OBJ_PATH}
			@make clean -C ${LIBFT}

fclean:		clean
			${RM} -f ${NAME}
			@make fclean -C ${LIBFT}

re:			fclean all

.PHONY:	all bonus clean fclean re
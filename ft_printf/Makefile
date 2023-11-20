NAME= libftprintf.a

INCLUDE= include

LIBFT= libft

CC= cc

CFLAGS= -Wall -Wextra -Werror -I

SRC= ft_printf.c \
	ft_putnbr.c \
	ft_putnbr_base.c \
	ft_printstr.c \
	ft_printch.c \
	ft_printpercent.c \
	ft_printpoint.c

AR= ar rcs
RM= rm -f

OBJ= ${SRC:.c=.o}

.c.o:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			${AR} $(NAME) $(OBJ)

clean:
			$(RM) -rf $(OBJ_DIR)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) -f ${NAME}
			$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:	all bonus clean fclean re
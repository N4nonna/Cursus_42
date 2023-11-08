
HEAD =../include/ft.h

CC=gcc
CFLAGS=-I -Wall -Wextra -Werror

_OBJ=../srcs/ft_putchar.c\
	../srcs/ft_swap.c\
	../srcs/ft_putstr.c\
	../srcs/ft_strlen.c\
	../srcs/ft_strcmp.c

$(OBJ): $(_OBJ) $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS)

OBJ= ../srcs/ft_putchar.o\
	../srcs/ft_swap.o\
	../srcs/ft_putstr.o\
	../srcs/ft_strlen.o\
	../srcs/ft_strcmp.o

all: $(OBJ)
	ar rcs libft.a $(OBJ)

libft.a: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm libft.a

re: fclean all
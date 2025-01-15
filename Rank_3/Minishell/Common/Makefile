# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mby <mby@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:10:52 by mbonny-e          #+#    #+#              #
#    Updated: 2024/09/23 18:01:25 by mby              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = maintestmakefile.c

SRCS = maintestmakefile.c
SRCS = maintestmakefile.c
SRCS = maintestmakefile.c
SRCS = maintestmakefile.c
SRCS = maintestmakefile.c

SRCS_D = srcs/

IN = minishell.h

IN_D = in/

OBJS = $(SRCS:.c=.o)

OBJS_D = .bin/

NAME = minishell

LIBS_ORI = libft/

LIBS = $(addprefix $(LIBS_D), libft.a)

LIBS_IN = libft.h

LIBS_IN_DEST = $(LIBS_IN_D)

LIBS_IN_D = $(IN_D)lib/

LIBS_SURNAME = -lft

LIBS_D = $(OBJS_D)lib/$(DEST)

DEST_FOR_LIB = ../$(LIBS_D)

CFLAGS = -Wall -Wextra -Werror

CFLAGS_TEST = $(CFLAGS) -g3 -fsanitize=address

CC = gcc

TEST_NAME = tester

TEST_MAIN = test_main.c

TEST_SRCS = $(TEST_MAIN) test1.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

all : $(NAME)

$(OBJS_D)%.o : $(SRCS_D)%.c $(IN_D)$(IN)
	@printf "%s is compiling ..." $@
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(IN_D) -I$(LIBS_IN_D)
	@printf "\b\b\b\b\b\b\bed\033[K\n"

$(NAME) : $(LIBS_IN_DEST) $(LIBS_D) $(LIBS)  $(addprefix $(OBJS_D), $(OBJS))
	@printf "%s is compiling ..." $@
	@$(CC) $(CFLAGS)  $(addprefix $(OBJS_D), $(OBJS)) -o $(NAME) -I$(IN_D) -I$(LIBS_IN_D) -L$(LIBS_D) $(LIBS_SURNAME)
	@printf "\b\b\b\b\b\b\bed\033[K\n"

$(TEST_NAME) : $(LIBS_IN_DEST) $(LIBS_D) $(LIBS)  $(addprefix $(OBJS_D), $(TEST_OBJS))
	@printf "%s is compiling ..." $@
	@$(CC) $(CFLAGS) -g3 $(addprefix $(OBJS_D), $(TEST_OBJS)) -o $(TEST_NAME) -I$(IN_D) -I$(LIBS_IN_D) -L$(LIBS_D) $(LIBS_SURNAME)
	@printf "\b\b\b\b\b\b\bed\033[K\n"

clean :
	@make fclean -C $(LIBS_ORI) --silent DEST=$(DEST_FOR_LIB)
	@rm -rf $(OBJS_D)
	@rm -rf $(LIBS_IN_D)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

norm :
	@echo "Norminette check :\n"
	@norminette srcs | grep Error | tr "" ""
	@echo "\nNorm on srcs checked\n"
	@norminette in/so_long.h | grep Error | tr "" ""
	@echo "\nNorm on in checked\n"

$(LIBS) : $(OBJS_D) $(LIBS_IN_D)$(LIBS_IN)
	@make --silent -C $(LIBS_ORI) DEST="$(DEST_FOR_LIB)"

$(OBJS_D) :
	@mkdir -p $@
	@mkdir -p $@/lib

$(LIBS_IN_D) :
	@mkdir -p $@

$(LIBS_IN_D)$(LIBS_IN) : $(LIBS_IN_D)
	@cp $(LIBS_ORI)in/libft.h $(LIBS_IN_DEST)

$(LIBS_D) :
	@mkdir -p $@

lib : $(LIB)

relib : clean lib

vpath %.c $(dir $(SRC))
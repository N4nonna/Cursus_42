NAME		= pipex
INCLUDES	= includes
SRCS_DIR	= src/
OBJS_DIR	= obj/

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# COLOR

GREEN		= '\033[0;32m'
RED			= '\033[1;31m'
GREY		= '\033[0;90m'
CYAN		= '\033[1;96m'
RESET		= '\033[0m'

# SOURCES

SRC_FILES	= pipex_utils\
			pipex

SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF		= .cache_exists

###

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@echo ${CYAN}"libft OK"${RESET}
			@$(CC) $(OBJS) -Llibft -lft -o $(NAME)
			@echo ${GREEN}"Make OK"${RESET}

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) -I $(INCLUDES) -I./libft/include -c $? -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)
			@echo ${CYAN}"Object dir created"${RESET}

clean:
			@make clean -C libft
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo ${RED}"Clean done"${RESET}

fclean:		clean
			@make fclean -C libft
			@$(RM) -f $(NAME)
			@echo ${RED}"Fclean done"${RESET}

re:			fclean all

.PHONY:		all bonus clean fclean re
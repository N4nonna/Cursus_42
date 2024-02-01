NAME		= pipex
INCLUDES	= includes
SRCS_DIR	= src/
OBJS_DIR	= obj/

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

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
			@$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) -I $(INCLUDES) -I./libft/include -c $? -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@make clean -C libft
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:		clean
			@make fclean -C libft
			@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
NAME		= so_long
INCLUDES	= includes
SRCS_DIR 	= src/
OBJS_DIR	= obj/
GIT_URL		= https://github.com/42Paris/minilibx-linux
GIT_DIR		= mlx_linux

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
AR			= ar rcs

# COLOR

GREEN		= '\033[0;32m'
RED			= '\033[1;31m'
GREY		= '\033[0;90m'
CYAN		= '\033[1;96m'
RESET		= '\033[0m'

# SOURCES

SRC_FILES	= main\
			init_vars\
			init_map\
			init_game\
			check_map\
			map_parsing\
			render_map\
			handle_input\
			close\
			end

SRCS 		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		= .cache_exists

all:		git_create ${NAME}

$(NAME):	$(OBJS)
			@make -C libft
			@make -C $(GIT_DIR)
			@$(CC) $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo ${CYAN}"Compilation done"${RESET}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJSF)
			@cd $(GIT_DIR)
			@$(CC) $(CFLAGS) -I $(INCLUDES) -I./libft/include -I./mlx_linux -c $? -o $@

git_create: 
			@git clone $(GIT_URL) $(GIT_DIR)

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@make clean -C libft
			@$(RM) -rf $(GIT_DIR)
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo ${GREEN}"Clean done"${RESET}

fclean:		clean
			@make fclean -C libft
			@$(RM) -f $(NAME)
			@echo ${GREEN}"Fclean done"${RESET}

re:			fclean all

.PHONY:	all git_create clean fclean re
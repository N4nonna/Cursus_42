NAME		= so_long
INCLUDES	= includes
SRCS_DIR 	= src2/
OBJS_DIR	= obj/

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# Sources

SRC_FILES	= main\
			init_map\
			init_game\
			check_map\
			render_map\
			handle_input\
			close\
			end

SRCS 		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		= .cache_exists

all:		${NAME}

$(NAME):	$(OBJS)
			@make -C libft
			@make -C mlx_linux
			@$(CC) $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) -I $(INCLUDES) -I./libft/include -I./mlx_linux -c $? -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@make clean -C libft
			@make clean -C mlx_linux
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

.PHONY:	all bonus clean fclean re
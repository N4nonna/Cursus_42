NAME		= pipex
NBONUS		= bonus_pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf

# COLOR

GREEN		= \033[0;32m
RED			= \033[1;31m
GREY		= \033[0;90m
CYAN		= \033[1;96m
RESET		= \033[0m

# SOURCES

INCLUDES	=	includes/
HEADER_SRCS	=	pipex_m.h pipex_bonus.h
HEADER		=	$(addprefix $(INCLUDES), $(HEADER_SRCS))

# MANDATORY

SRCS_DIR	= mandatory/
SRC_FILES	= m_child.c\
			m_pipex.c\
			m_free.c\
			m_error.c\
			m_utils.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS		= $(SRCS:.c=.o)

# BONUS

BONUS_DIR	= bonus/
BONUS_FILES	= b_pipex.c\
			b_child.c\
			b_utils.c\
			b_free.c\
			b_error.c\
			b_heredoc.c
BONUS_SRCS	= $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

###

all:		$(NAME)
bonus:		$(NBONUS)

$(NAME):	$(OBJS)
			@make -C libft
			@echo "$(CYAN)libft OK!$(RESET)"
			@$(CC) $(OBJS) -Llibft -lft -o $(NAME)
			@echo "$(GREEN)$(NAME) OK!$(RESET)"

$(NBONUS):	$(BONUS_OBJS)
			@make -C libft
			@echo "$(CYAN)libft OK!$(RESET)"
			@$(CC) $(BONUS_OBJS) -Llibft -lft -o $(NBONUS)
			@echo "$(GREEN)$(NBONUS) OK!$(RESET)"

%.o:		%.c $(HEADER) Makefile
			@${CC} ${CFLAGS} -I $(INCLUDES) -I./libft/include -c $< -o $@

clean:
			@make clean -C libft
			@$(RM) $(OBJS)
			@$(RM) $(BONUS_OBJS)
			@echo "$(RED)Object files deleted!$(RESET)"

fclean:		clean
			@make fclean -C libft
			@$(RM) $(NAME)
			@$(RM) $(NBONUS)
			@echo "$(RED)All clean!$(RESET)"

re:			fclean all

.PHONY:		all bonus clean fclean re
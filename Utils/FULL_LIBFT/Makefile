NAME		=	libft.a
INCLUDES	=	include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Sources

FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstlast \
				ft_lstnew ft_lstsize

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_split ft_strappend ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr

FTPRINTF_DIR	=	ft_printf/
FTPRINTF	=	ft_printf ft_print_int ft_print_pointer ft_print_string

FTGET_DIR	=	ft_get/
FTGET		=	get_next_line #get_next_line_utils

FTUTILS_DIR	=	ft_utils/
FTUTILS		=	ft_free_tab

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))
SRC_FILES+=$(addprefix $(FTGET_DIR),$(FTGET))
SRC_FILES+=$(addprefix $(FTUTILS_DIR),$(FTUTILS))

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTIS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTLST_DIR)
			@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPUT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTTO_DIR)
			@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPRINTF_DIR)
			@mkdir -p $(OBJS_DIR)$(FTGET_DIR)
			@mkdir -p $(OBJS_DIR)$(FTUTILS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all


.PHONY:		all clean fclean re

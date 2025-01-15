# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:10:52 by mbonny-e          #+#    #+#              #
#    Updated: 2024/06/05 14:38:14 by mabonny-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEST = ./

NAME = libft.a

NAME_DYN = libft.so

SRCS_D = srcs/

DIR_STRUCT1 =	$(ARR_D) $(CONV_D) $(EXT_D) $(LST_D) $(MATH_D)				\
				$(MEM_D) $(PUT_D)											\
				$(DIR_STRUCT2)												\

DIR_STRUCT2 =	$(addprefix $(EXT_D), $(EXT_SUBDIR))						\
				$(addprefix $(LST_D), $(LST_SUBDIR))						\
				$(addprefix $(PUT_D), $(PUT_SUBDIR))						\

SRCS =	$(addprefix $(ARR_D), $(SRCS_ARR)) 									\
		$(addprefix $(CONV_D), $(SRCS_CONV))								\
		$(addprefix $(EXT_D), $(SRCS_EXT))									\
		$(addprefix $(LST_D), $(SRCS_LST))									\
		$(addprefix $(MATH_D), $(SRCS_MATH))								\
		$(addprefix $(MEM_D), $(SRCS_MEM))									\
		$(addprefix $(PUT_D), $(SRCS_PUT))									\

ARR_D =	ft_arr/

SRCS_ARR =	ft_arrintmanip.c ft_arrintmapdup.c ft_arrpmanip.c				\
			ft_arrpmapdup.c ft_arrstrmanip.c ft_arrstrmapdup.c				\
			ft_indexintarr.c ft_indexnintarr.c ft_indexparr.c ft_indexstr.c	\
			ft_intarrtest1.c ft_intarrtest2.c ft_llintarrtest1.c			\
			ft_parrtest1.c ft_parrtest2.c ft_split.c ft_split_set.c			\
			ft_strchrcmp.c ft_strjoin.c ft_strlcc.c ft_strlen.c				\
			ft_strmanip.c ft_strmapdup.c ft_strstr.c ft_strtest1.c			\
			ft_strtest2.c													\

CONV_D =	ft_conv/

SRCS_CONV =	ft_aarrtoiarr.c ft_aarrtoparr.c ft_aarrtouarr.c ft_atoi.c		\
			ft_atou.c ft_itoa.c ft_lstdlst.c ft_parrlstdlst.c ft_utoa.c		\

EXT_D =	ft_ext/

EXT_SUBDIR =	$(EXT_FILE_D) $(EXT_EXE_D)

SRCS_EXT =	$(addprefix $(EXT_FILE_D), $(SRCS_EXT_FILE))					\

EXT_FILE_D =	file/

SRCS_EXT_FILE = ft_gnl.c ftu_gnl.c ft_filetolst.c							\

EXT_EXE_D =	ex/

LST_D =	ft_lst/

LST_SUBDIR = $(LST_DLST_D)

SRCS_LST =	ft_lstcreate.c ft_lstmanip.c ft_lstmapdup.c	ft_lstdel.c			\
			ft_lstparse2.c ft_lstparse1.c									\
			$(addprefix $(LST_DLST_D), $(SRCS_LST_DLST))					\


LST_DLST_D =	ft_dlst/

SRCS_LST_DLST =	ft_dlstcreate.c ft_dlstdel.c ft_dlstparse1.c				\
				ft_dlstparse2.c ft_dlstsize.c ft_dlstmanip.c				\
				ft_dlstmapdup.c												\

MATH_D =	ft_math/

SRCS_MATH =	ft_base.c ft_testchar.c ft_tosign.c ft_small.c ft_worst1.c		\
			ft_worst2.c ft_best1.c ft_best2.c ft_great.c ft_sign.c			\
			ft_power.c ft_overflow.c ft_lstcomp.c							\

MEM_D =	ft_mem/

SRCS_MEM =	ft_memparse.c ft_memmanip.c ft_memallocfree.c ft_membase.c		\

PUT_D =	ft_put/

PUT_SUBDIR =	$(PUT_CLASSIC_D) $(PUT_COMPLEX_D) $(PUT_PPUT_D)				\
				$(PUT_PRINTF_D)												\

SRCS_PUT =	$(addprefix $(PUT_CLASSIC_D), $(SRCS_PUT_CLASSIC))				\
			$(addprefix $(PUT_COMPLEX_D), $(SRCS_PUT_COMPLEX))				\
			$(addprefix $(PUT_PPUT_D), $(SRCS_PUT_PPUT))					\
			$(addprefix $(PUT_PRINTF_D), $(SRCS_PUT_PRINTF))				\

PUT_CLASSIC_D =	classic/

SRCS_PUT_CLASSIC =	ft_putchar.c ft_putstr.c ft_putuns.c ft_putendl.c		\
					ft_putnbr.c ft_putnbr_base.c ft_putuns_base2.c			\
					ft_putuns_base.c ft_putnbrll.c ft_putlluns.c 			\
					ft_putlluns_base.c ft_putlluns_base2.c ft_putstrn.c		\
					ft_putnbrll_base.c										\

PUT_COMPLEX_D =	complex/

SRCS_PUT_COMPLEX =	ft_putdlst_def.c ft_putintarr_def.c ft_putlst_def.c		\
					ft_putstrarr_def.c ft_putintarr_base_def.c				\

PUT_PPUT_D =	pput/

SRCS_PUT_PPUT =	ft_pputchar.c ft_pputendl.c ft_pputlluns_base.c				\
				ft_pputlluns.c ft_pputnbr_base.c ft_pputnbr.c				\
				ft_pputnbrll_base.c ft_pputnbrll.c ft_pputstr.c				\
				ft_pputuns_base.c ft_pputuns.c								\

PUT_PRINTF_D =	printf/

SRCS_PUT_PRINTF =	ft_dprintf.c ft_printf.c ft_snprintf.c ft_sprintf.c		\
					ftu_printf_processflagextra.c							\

OBJS = $(SRCS:.c=.o)

OBJS_D = .bin/

OBJS_DYN_D = dyn/

IN_D = in/

IN = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

# TEST

all : testoff $(DEST)$(NAME)

libft_dyn : testoff $(DEST)$(NAME_DYN)


COMPILATION_COUNT := 0
NUMBER_SRCS := $(shell find srcs/ -type f -name "*.c" | wc -l)

$(OBJS_D)%.o : $(SRCS_D)%.c
	@$(CC) $(CFLAGS) -fPIE -c $< -I$(IN_D) -o $@
	@$(eval COMPILATION_COUNT := $(shell echo 								\
		$$(($(COMPILATION_COUNT) + 1))))
	@printf "\r\033[KCompiling libft with $(CC) %0.3i/%i $<"  $(COMPILATION_COUNT) 	\
	$(NUMBER_SRCS)

$(OBJS_D)$(OBJS_DYN_D)%.o : $(SRCS_D)%.c
	@$(CC) $(CFLAGS) -nostartfiles -fPIC -c $< -I$(IN_D) -o $@
	@$(eval COMPILATION_COUNT := $(shell echo								\
		$$(($(COMPILATION_COUNT) + 1))))
	@printf "\r\033[KCompiling libft with $(CC)for dynamic %0.3i/%i $<"				\
		$(COMPILATION_COUNT)  $(NUMBER_SRCS)

$(OBJS_D) :
	@mkdir -p $(OBJS_D)
	@mkdir -p $(addprefix $(OBJS_D), $(DIR_STRUCT1))

$(OBJS_D)$(OBJS_DYN_D) : $(OBJS_D)
	@mkdir -p $(OBJS_D)$(OBJS_DYN_D)
	@mkdir -p $(addprefix $(OBJS_D)$(OBJS_DYN_D), $(DIR_STRUCT1))

$(DEST)$(NAME) : $(OBJS_D) $(addprefix $(OBJS_D), $(OBJS))
	@printf "\r\033[KCompiling libft with $(CC) %0.3i/%i Done !\n"  $(COMPILATION_COUNT)		\
		$(shell find srcs/ -type f -name "*.c" | wc -l)
	@printf "Linking for libInMaking is ... "
	@ar rsc libInMaking $(addprefix $(OBJS_D), $(OBJS))
	@printf "\b\b\b\bdone and ... "
	@ranlib libInMaking
	@printf "\b\b\b\branlib"
	@mv libInMaking $@
	@printf "\n$@ is made !\n"


$(DEST)$(NAME_DYN) : $(OBJS_D)$(OBJS_DYN_D) $(addprefix $(OBJS_D)$(OBJS_DYN_D), 	\
$(OBJS))
	@printf "\r\033[KCompiling for dynamic %0.3i/%i Done !\n"				\
		$(COMPILATION_COUNT)  $(shell find srcs/ -type f -name "*.c" | wc -l)
	@printf "Linking for libDynInMaking is ... "
	@gcc -nostartfiles -shared -o libInMaking $(addprefix 					\
		$(OBJS_D)$(OBJS_DYN_D), $(OBJS))
	@printf "\b\b\b\bdone "
	@mv libInMaking $@
	@printf "\n$@ is made !\n"

clean : testoff 
	@rm -rf $(OBJS_D)
	
fclean : clean
	@rm -rf $(DEST)$(NAME) $(DEST)$(NAME_DYN)

re : fclean all

reatdest : re
	@mv $(NAME) $(DEST)

norm :
	@norminette srcs | grep Error | xargs -d \n echo 
	@echo Norm on srcs checked
	@norminette in | grep Error | xargs -d \n echo
	@echo Norm on in checked

.PHONY: bonus clean fclean all re so libft_dyn testsave testload testdelete
.PHONY: teston testoff test runtest testlibclean testlibfclean testclean
.PHONY: testfclean testfullclean testfullfclean retest refulltest libftt
.PHONY: libftt_dyn reruntest refullruntest atdest reatdest fcleanatdest norm
.PHONY: testgitclean testgit
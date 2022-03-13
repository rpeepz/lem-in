# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 20:19:37 by rpapagna          #+#    #+#              #
#    Updated: 2021/11/30 12:26:37 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
AUTHOR	= rpapagna

CFLAGS	= -Wall -Wextra -Wextra -g
INCL	= -I includes/
OBJ_PATH= obj

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
CYN		=\033[0;36m
NC		=\033[0m

#PATHS
OBJ_PATH	= obj
LIB_PATH	= srcs
ALLOC_PATH	=$(LIB_PATH)/allocate
BIGNBR_PATH	=$(LIB_PATH)/big_number
HELPER_PATH	=$(LIB_PATH)/big_number/helper
COMPR_PATH	=$(LIB_PATH)/comparison
COUNT_PATH	=$(LIB_PATH)/count
PRNTF_PATH	=$(LIB_PATH)/ft_printf
SPRNTF_PATH	=$(LIB_PATH)/ft_sprintf
IS_PATH		=$(LIB_PATH)/is_type
LIST_PATH	=$(LIB_PATH)/list
MANIP_PATH	=$(LIB_PATH)/manipulate
PRINT_PATH	=$(LIB_PATH)/print


ALLOC 	= ft_itoa_base.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_strcnew.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strjoin3.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strndup.c \
		ft_strnew.c \
		ft_strpop.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_uitoa_base.c
BIGNBR	= bignum_add_neg.c \
		bignum_add.c \
		bignum_copy.c \
		bignum_decrement.c \
		bignum_del.c \
		bignum_divide.c \
		bignum_eq.c \
		bignum_gt.c \
		bignum_increment.c \
		bignum_init.c \
		bignum_lt.c \
		bignum_minus.c \
		bignum_mod.c \
		bignum_multiply.c \
		bignum_swap.c \
		bignum_trunc.c
HELPER	= bignum_compare.c \
		carry.c \
		do_dif.c \
		do_quotient.c \
		do_sum.c \
		init_remainder.c \
		init_result.c
COMPR	= ft_memcmp.c \
		ft_strcmp.c \
		ft_strequ.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strnstr.c \
		ft_strstr.c
COUNT	= ft_abs.c \
		ft_atoi.c \
		ft_atoull.c \
		ft_countwords.c \
		ft_hextoull.c \
		ft_intlen.c \
		ft_map_zero.c \
		ft_strchri.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strrchri.c
PRNTF	= convert_b.c \
		convert_c.c \
		convert_f.c \
		convert_i.c \
		convert_o.c \
		convert_p.c \
		convert_percent.c \
		convert_s.c \
		convert_u.c \
		convert_x.c \
		do_things.c \
		finders.c \
		get_mods.c
SPRNTF	= c_to_buf.c \
		get_mod.c \
		i_to_buf.c \
		s_to_buf.c \
		sprintf_helper.c \
		u_to_buf.c \
		x_to_buf.c
IS		= ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c
LIST	=ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c
MANIP	= ft_bzero.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strrchr.c \
		ft_tolower_str.c \
		ft_tolower.c \
		ft_toupper_str.c \
		ft_toupper.c \
		reverse_array.c
PRINT	= ft_printf.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_sprintf.c
SRCS	= ft_pipewrench.c \
		get_next_line.c \
		queue.c

OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(ALLOC:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(BIGNBR:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(HELPER:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(COMPR:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(COUNT:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(PRNTF:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(SPRNTF:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(IS:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(LIST:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(MANIP:.c=.o))
OBJ		+= $(addprefix $(OBJ_PATH)/,$(PRINT:.c=.o))

.PHONY: clean debug

all:	$(NAME)

clean:
		@printf "[$(RED)clean   obj$(NC)]\t[:#         :]\r"
		@rm -rf $(OBJ_PATH)
		@printf "[$(RED)clean libft$(NC)]\t[:##########:]\n"

fclean: clean
		@printf "[$(RED)rm    libft$(NC)]\t[:###       :]\r"
		@rm -rf $(OBJ_PATH)
		@printf "[$(RED)rm    libft$(NC)]\t[:######    :]\r"
		@rm -rf $(NAME)
		@printf "[$(RED)full  clean$(NC)]\t[:##########:]\n"

re: fclean all

$(NAME): $(OBJ)
		@printf "[ Archiving ]\t[:######### :]\r"
		@ar -rcs $(NAME) $(OBJ)
		@printf "[$(CYN) Complete! $(NC)]\t[:##########:]\n"

$(OBJ_PATH):
		@printf "[  compile  ]\t[:          :]\r"
		@mkdir -p $@

$(OBJ_PATH)/%.o: $(LIB_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:          :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(ALLOC_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:#         :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(BIGNBR_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:#         :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(HELPER_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:##        :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(COMPR_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:##        :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(COUNT_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:###       :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(PRNTF_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:####      :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SPRNTF_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:#####     :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(IS_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:######    :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(LIST_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:#######   :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(MANIP_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:########  :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(OBJ_PATH)/%.o: $(PRINT_PATH)/%.c | $(OBJ_PATH)
		@printf "[  compile  ]\t[:######### :]\r"
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<
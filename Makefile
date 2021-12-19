# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:14:34 by rpapagna          #+#    #+#              #
#    Updated: 2021/12/19 18:14:34 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem_in

CFLAGS	= -Wall -Werror -Wextra -g

#PATHS
LIB				= .libft.a
SRC_PATH		= srcs/
INC				= -I includes/

SRCS	= lem-in.c \
		build_farm.c \
		build_tree.c \
		run_ants.c \
		validate.c

.PHONY: clean

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)

re: fclean all

$(NAME):
	@gcc $(CFLAGS) $(INC) -o $(NAME) $(addprefix $(SRC_PATH),$(SRCS)) $(LIB)
	@printf "to run:\n"
	@printf "./lem_in < <path to map>\n"

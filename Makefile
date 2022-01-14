# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:14:34 by rpapagna          #+#    #+#              #
#    Updated: 2022/01/12 13:08:34 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem_in
AUTHOR	= rpapagna
CFLAGS	= -Wall -Werror -Wextra -g

#PATHS
LIB		= .libft.a
SRC_PATH= srcs/
INC_PATH= includes/
OBJ_PATH= obj

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
NC		=\033[0m

SRCS	= add_edge.c \
		create_graph.c \
		find_path.c \
		graph_undirected.c \
		lem-in.c \
		queue.c \
		run_ants.c \
		split_line.c \
		validate.c

OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

.PHONY: clean

all: $(NAME)

clean:
	@printf "[$(RED)clean   obj$(NC)]\t[:#         :]\r"
	@rm -rf $(OBJ_PATH)
	@printf "[$(RED)clean   obj$(NC)]\t[:##########:]\n"

fclean: clean
	@printf "[$(RED)full  clean$(NC)]\t[:#         :]\r"
	@rm -rf $(NAME).dSYM
	@printf "[$(RED)full  clean$(NC)]\t[:###       :]\r"
	@rm -rf $(NAME)*.stackdump
	@printf "[$(RED)full  clean$(NC)]\t[:#####     :]\r"
	@rm -rf $(NAME).h.gch
	@printf "[$(RED)full  clean$(NC)]\t[:########  :]\r"
	@rm -rf $(NAME)
	@printf "[$(RED)full  clean$(NC)]\t[:##########:]\n"

re: fclean all

$(NAME): $(OBJ)
	@printf "[$(NAME)]\t[:########  :]\r"	
	@gcc $(CFLAGS) $(OBJ_PATH)/*.o $(LIB) -o $(NAME)
	@printf "[$(GREEN)$(NAME)$(NC)]\t[:##########:]\n"	
	@printf "to run:\n"
	@printf "./lem_in < <path to map>\n"

$(OBJ_PATH):
	@printf "[$(NAME)]\t[:#         :]\r"	
	@mkdir -p $@

$(OBJ_PATH)/%.o: srcs/%.c $(INC_PATH)/*.h | $(OBJ_PATH)
	@printf "[$(NAME)]\t[:######    :]\r"
	@gcc $(CFLAGS) -I $(INC_PATH) -o $@ -c $<
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

NAME	= lem-in
ARCHIVE	= libft/libft.a
AUTHOR	= rpapagna
CFLAGS	= -Wall -Werror -Wextra -g

#PATHS
SRC_PATH= srcs/
INC_PATH= includes/
OBJ_PATH= obj

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

SRCS	= add_edge.c \
		continue_movement.c \
		create_graph.c \
		find_path.c \
		graph_undirected.c \
		lem_in.c \
		path_info.c \
		path_matrix.c \
		print.c \
		queue.c \
		reverse_array.c \
		run_ants.c \
		split_line.c \
		unvisit_neighbors.c \
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

$(NAME): $(ARCHIVE) $(OBJ)
	@printf "[$(NAME)]\t[:########  :]\r"	
	@gcc $(CFLAGS) $(OBJ_PATH)/*.o $(ARCHIVE) -o $(NAME)
	@printf "[$(GREEN)$(NAME)$(NC)]\t[:##########:]\n\n"

	@printf "$(YELLOW)Maps are available in 'm/' and 'maps/' directories$(NC) \n"
	@printf "to run:\n"
	@printf "./lem-in < <path to map>\n"
	@printf "$(GREEN)to run with visualizer:\n$(NC)"
	@printf "./lem-in < <path to map> | python3 viz/viz.py\n"

$(OBJ_PATH):
	@printf "[$(NAME)]\t[:#         :]\r"	
	@mkdir -p $@

$(OBJ_PATH)/%.o: srcs/%.c $(INC_PATH)/*.h | $(OBJ_PATH)
	@printf "[$(NAME)]\t[:######    :]\r"
	@gcc $(CFLAGS) -I $(INC_PATH) -o $@ -c $<

$(ARCHIVE):
	@make -C libft

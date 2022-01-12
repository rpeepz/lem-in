/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:53:54 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 12:17:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define START "##start"
# define END "##end"

typedef struct 		s_edge
{
	char			*dest_id;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_graph
{
	char			*node_id;
	t_point			location;
	t_edge			*edges;
	struct s_graph	*next;
}					t_graph;

typedef struct		s_farm
{
	char			*id;
	int				child_count;
	struct s_farm	**child;
	struct s_farm	*parent;
}					t_farm;

typedef struct		s_lem_in
{
	int				check_start;
	int				check_end;
	size_t			ants;
	t_graph			*adj_list;
	t_farm			*farm;
	char			*start_id;
	char			*end_id;
}					t_lem_in;


char				**split_line(char *s, char c);
int					create_graph(char *line, t_lem_in *lem_in);
void				add_edge(char *line, t_lem_in *farm);
void				build_graph1(t_lem_in *farm);

int					validate(t_lem_in *farm);
void				run_ants(t_lem_in *farm);

#endif

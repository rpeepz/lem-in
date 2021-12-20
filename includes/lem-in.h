/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:53:54 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/18 15:09:10 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define START "##start"
# define END "##end"

typedef struct 		s_link
{
	char			*link;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*id;
	t_point			location;
	t_link			*links;
	struct s_room	*next;
}					t_room;

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
	t_room			*room;
	t_farm			*farm;
	char			*start;
	char			*end;
}					t_lem_in;

void				build_link(char *line, t_lem_in *farm);
void				build_room(char *line, t_lem_in *farm);
void				build_tree(t_lem_in *farm);
int					validate(t_lem_in *farm);
void				run_ants(t_lem_in *farm);

#endif

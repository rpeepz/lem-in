/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:12:32 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 12:20:55 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_edge(char *line, t_lem_in *lem_in)
{
	char	**buf;
	t_edge	*new_edge;
	t_graph	*node;
	t_edge	*edge;
	int		i;

	buf = split_line(line, '-');
	node = lem_in->adj_list;
	while (node)
	{
		if (!ft_strcmp(node->node_id, buf[0]))
		{
			new_edge = ft_memalloc(sizeof(t_edge));
			new_edge->dest_id = ft_strdup(buf[1]);
			edge = node->edges;
			new_edge->next = edge;
			node->edges = new_edge;
			break ;
		}
		node = node->next;
	}
	i = -1;
	while (buf[++i])
		ft_memdel((void **)&buf[i]);
	ft_memdel((void **)&buf);
}

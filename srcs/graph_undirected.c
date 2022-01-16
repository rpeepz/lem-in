/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_undirected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:45:37 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/14 15:45:37 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	append_edge_to_node(t_graph *adj_list, t_edge *edge, char *node_id)
{
	t_graph		*n;
	t_edge		*new_edge;
	t_edge		*head;

	n = adj_list;
	while (ft_strcmp(n->node_id, edge->dest_id))
		n = n->next;
	head = n->edges;
	while (n->edges)
	{
		if (!ft_strcmp(n->edges->dest_id, node_id))
			return ;
		if (!n->edges->next)
			break ;
		n->edges = n->edges->next;
	}
	new_edge = ft_memalloc(sizeof(t_edge));
	new_edge->dest_id = ft_strdup(node_id);
	if (n->edges)
	{
		n->edges->next = new_edge;
		n->edges = head;
	}
	else
		n->edges = new_edge;
}

void		graph_undirected(t_graph *adj_list)
{
	t_graph		*node;
	t_edge		*edge;

	node = adj_list;
	while (node)
	{
		edge = node->edges;
		while (edge)
		{
			append_edge_to_node(adj_list, edge, node->node_id);
			edge = edge->next;
		}
		node = node->next;
	}
}

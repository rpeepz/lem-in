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

static size_t	count_edges(t_edge *edges)
{
	size_t	n;
	t_edge	*edge;

	n = 0;
	edge = edges;
	while (edge)
	{
		++n;
		edge = edge->next;
	}
	return (n);
}

static t_graph	*push_start_to_front(t_graph *adj_list, char *start_id)
{
	t_graph	*head;
	t_graph	*prev;
	t_graph	*tmp;

	head = adj_list;
	while (ft_strcmp(start_id, adj_list->node_id))
	{
		prev = adj_list;
		adj_list = adj_list->next;
	}
	prev->next = adj_list->next;
	tmp = head;
	adj_list->next = tmp;
	return (adj_list);
}

static void		append_edge_to_node(t_graph *adj_list, t_edge *edge, char *node_id)
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

void			graph_undirected(t_lem_in *lem_in)
{
	t_graph		*node;
	t_edge		*edge;

	node = lem_in->adj_list;
	while (node)
	{
		edge = node->edges;
		while (edge)
		{
			append_edge_to_node(lem_in->adj_list, edge, node->node_id);
			edge = edge->next;
		}
		node = node->next;
	}
	lem_in->adj_list = push_start_to_front(lem_in->adj_list, lem_in->start_id);
	lem_in->count_paths = count_edges(lem_in->adj_list->edges);
}

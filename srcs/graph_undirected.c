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

#include "lemin.h"

static int	count_edges(t_edge *edges)
{
	int		n;
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

/*
*	insert node with matching start_id to the front of the adjacency list
*/
static t_graph	*push_start_to_front(t_graph *adj_list, char *start_id)
{
	t_graph	*prev;
	t_graph	*tmp;

	if (ft_strcmp(start_id, adj_list->node_id))
	{
		tmp = adj_list;
		while (ft_strcmp(start_id, tmp->node_id))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = tmp->next;
		tmp->next = adj_list;
		adj_list = tmp;
	}
	return (adj_list);
}

static void	append_edge_to_node(t_graph *n, char *node_id)
{
	t_edge		*new_edge;
	t_edge		*head;

	head = n->edges;
	while (n->edges)
	{
		if (!ft_strcmp(n->edges->dest_id, node_id))
		{
			n->edges = head;
			return ;
		}
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

/*
*	convert the directed adjacency list to an undirected graph
*/
void	graph_undirected(t_lem_in *lem_in)
{
	t_graph		*node;
	t_graph		*tmp;
	t_edge		*edge;

	node = lem_in->adj_list;
	while (node)
	{
		edge = node->edges;
		while (edge)
		{
			tmp = lem_in->adj_list;
			while (ft_strcmp(tmp->node_id, edge->dest_id))
				tmp = tmp->next;
			append_edge_to_node(tmp, node->node_id);
			edge = edge->next;
		}
		node = node->next;
	}
	lem_in->adj_list = push_start_to_front(lem_in->adj_list, lem_in->start_id);
	lem_in->count_paths = count_edges(lem_in->adj_list->edges);
}

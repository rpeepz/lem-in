/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:26:23 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/29 19:12:15 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		push_start_to_front(t_lem_in *lem_in)
{
	t_graph	*head;
	t_graph	*prev;
	t_graph	*tmp;

	head = lem_in->adj_list;
	while (ft_strcmp(lem_in->start_id, lem_in->adj_list->node_id))
	{
		prev = lem_in->adj_list;
		lem_in->adj_list = lem_in->adj_list->next;
	}
	prev->next = lem_in->adj_list->next;
	tmp = head;
	lem_in->adj_list->next = tmp;
}

static t_farm	*check_parents(t_farm *head, t_farm* parent, t_edge *edge)
{
	int		i;
	int		j;
	t_farm	*farm;
	t_edge	*tmp_l;

	farm = head;
	if (farm)
	{
		i = -1;
		while (++i < farm->child_count)
		{
			tmp_l = edge;
			while (tmp_l)
			{
				if (!ft_strcmp(farm->id, tmp_l->dest_id))
					return (farm);
				tmp_l = tmp_l->next;
			}
		}
		j = -1;
		while (++j < farm->child_count)
			return (check_parents(farm->child[j], parent, edge));
	}
	return (NULL);
}

static void		create_children(t_farm *head, t_farm *parent, t_edge *edge)
{
	int		n;
	t_edge	*tmp_l;
	t_farm	*farm;

	n = 0;
	tmp_l = edge;
	while (n < parent->child_count)
	{
		farm = check_parents(head, parent, edge);
		if (farm)
			parent->child[n] = farm;
		else
		{
			parent->child[n] = (t_farm*)ft_memalloc(sizeof(*parent->child[n]));
			parent->child[n]->id = ft_strdup(tmp_l->dest_id);
			parent->child[n]->parent = parent;
		}
		tmp_l = tmp_l->next;
		++n;
	}
}

static void		count_edges(t_farm *parent, t_graph *node)
{
	t_edge	*edge;

	if (parent->child_count)
		return ;
	edge = node->edges;
	while (edge)
	{
		++parent->child_count;
		edge = edge->next;
	}
	parent->child =\
	(t_farm**)ft_memalloc(sizeof(*parent->child) * (parent->child_count + 1));
}

static void		assign_tree(t_farm *head, int n, t_farm **kids, t_graph *nodes)
{
	t_graph	*node;
	t_farm	*child;
	t_farm	**children;
	int		i;

	i = -1;
	while (++i < n)
	{
		child = kids[i];
		if (child->child_count)
			continue ;
		node = nodes;
		while (ft_strcmp(child->id, node->node_id))
			node = node->next;
		count_edges(child, node);
		create_children(head, child, node->edges);
		children = child->child;
		assign_tree(head, child->child_count, children, nodes);
	}
}

void			build_graph1(t_lem_in *lem_in)
{
	t_farm	*farm;

	push_start_to_front(lem_in);
	farm = (t_farm*)ft_memalloc(sizeof(*farm));
	farm->id = ft_strdup(lem_in->adj_list->node_id);
	farm->parent = NULL;
	lem_in->farm = farm;
	count_edges(farm, lem_in->adj_list);
	create_children(farm, farm, lem_in->adj_list->edges);
	assign_tree(farm, farm->child_count, farm->child, lem_in->adj_list);
}

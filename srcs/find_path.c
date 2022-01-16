/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:26:23 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 19:12:15 by rpapagna         ###   ########.fr       */
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

static int		visit_neighbors(t_edge *neighbor, char **visited)
{
	size_t	i;

	i = 0;
	while (visited[i])
	{
		if (!ft_strcmp(neighbor->dest_id, visited[i]))
			return (1);
		++i;
	}
	visited[i] = neighbor->dest_id;
	return (0);
}

static void		queue_neighbors(t_lem_in *lem_in, t_graph *pop, char ***prev)
{
	t_edge	*neighbor;
	t_graph *node;
	
	neighbor = pop->edges;
	while (neighbor)
	{
		if (!visit_neighbors(neighbor, lem_in->visited))
		{
			path_matrix_save(prev, neighbor->dest_id, pop->node_id);
			node = lem_in->adj_list;
			while (node && ft_strcmp(node->node_id, neighbor->dest_id))
				node = node->next;
			enqueue(lem_in->queue, node);
		}
		neighbor = neighbor->next;
	}
}

void			find_path(t_lem_in *lem_in)
{
	t_graph		*pop;
	int			found_path;

	push_start_to_front(lem_in);
	lem_in->queue = queue_init();
	enqueue(lem_in->queue, lem_in->adj_list);
	lem_in->visited = ft_memalloc(sizeof(char*) * (lem_in->count_nodes + 1));
	lem_in->prev = path_matrix_init(lem_in->count_nodes, 2);
	lem_in->visited[0] = queue_peek(lem_in->queue);
	found_path = 0;
	while (!found_path && !queue_is_empty(lem_in->queue))
	{
		pop = dequeue(lem_in->queue);
		if (!ft_strcmp(pop->node_id, lem_in->end_id))
			found_path = 1;
		else
			queue_neighbors(lem_in, pop, lem_in->prev);
	}
	if (!path_matrix_reconstruct(lem_in))
		ft_memdel((void**)&lem_in->path);
}

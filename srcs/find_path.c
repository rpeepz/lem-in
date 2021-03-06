/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:26:23 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/02 14:20:50 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	visit_neighbors(t_edge *neighbor, char **visited, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (visited[i] && !ft_strcmp(neighbor->dest_id, visited[i]))
			return (1);
		++i;
	}
	i = 0;
	while (visited[i])
		++i;
	visited[i] = neighbor->dest_id;
	return (0);
}

static void	queue_neighbors(t_lem_in *lem_in, t_graph *pop, t_queue *queue)
{
	t_edge	*neighbor;
	t_graph	*node;

	neighbor = pop->edges;
	while (neighbor)
	{
		if (!visit_neighbors(neighbor, lem_in->visited, lem_in->count_nodes))
		{
			path_matrix_save(lem_in->prev, neighbor->dest_id, pop->node_id);
			node = lem_in->adj_list;
			while (node && ft_strcmp(node->node_id, neighbor->dest_id))
				node = node->next;
			enqueue(queue, node);
		}
		neighbor = neighbor->next;
	}
}

/*
*	use a breadth first search algorithm to navigate from the start to end
*/
static void	bfs(t_lem_in *lem_in)
{
	t_queue		*queue;
	t_graph		*pop;

	queue = queue_init();
	enqueue(queue, lem_in->adj_list);
	pop = queue_peek(queue);
	lem_in->visited[0] = pop->node_id;
	while (!queue_is_empty(queue))
	{
		pop = dequeue(queue);
		if (!ft_strcmp(pop->node_id, lem_in->end_id))
		{
			while (!queue_is_empty(queue))
				dequeue(queue);
			break ;
		}
		else
			queue_neighbors(lem_in, pop, queue);
	}
	ft_memdel((void **)&queue);
}

/*
*	search through adjacency list and store each possible path in "path" array
*	using a bfs.
*/
void	find_path(t_lem_in *lem_in)
{
	int		k;

	lem_in->visited = ft_memalloc(sizeof(char *) * (lem_in->count_nodes + 1));
	lem_in->path = path_matrix_init(lem_in->count_paths, lem_in->count_nodes);
	k = 0;
	while (k < lem_in->count_paths)
	{
		lem_in->prev = path_matrix_init(lem_in->count_nodes, 2);
		bfs(lem_in);
		path_matrix_reconstruct(lem_in, k);
		if (reverse_array(lem_in->path[k], lem_in->count_nodes) < 2)
			lem_in->path[k][0] = NULL;
		else if (!ft_strcmp(lem_in->path[k][0], lem_in->start_id))
			unvisit_neighbors(lem_in, k);
		++k;
	}
}

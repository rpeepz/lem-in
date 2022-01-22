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

//TODO
// consolidate and optimize unvisit function

static void		unvisit(t_lem_in *lem_in, size_t k)
{
	size_t		i;
	size_t		j;
	size_t		n;
	int			part_of_path;

	i = 0;
	while (i < lem_in->count_nodes)
	{
		if (!lem_in->visited[i] || !ft_strcmp(lem_in->visited[i], lem_in->end_id))
			lem_in->visited[i] = NULL;
		else
		{
			part_of_path = 0;
			n = 0;
			while (!part_of_path && n <= k)
			{
				j = 0;
				while (!part_of_path && lem_in->path[n][j])
				{
					if (!ft_strcmp(lem_in->visited[i], lem_in->path[n][j]))
						part_of_path = 1;
					else
						++j;
				}
				if (!part_of_path)
					++n;
			}
			if (n > k)
				--n;
			lem_in->visited[i] = lem_in->path[n][j];
		}
		++i;
	}
}

static int		visit_neighbors(t_edge *neighbor, char **visited, size_t n)
{
	size_t	i;

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

static void		queue_neighbors(t_lem_in *lem_in, t_graph *pop, t_queue *queue)
{
	t_edge	*neighbor;
	t_graph *node;
	
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

static void		bfs(t_lem_in *lem_in)
{
	t_queue		*queue;
	t_graph		*pop;

	queue = queue_init();
	enqueue(queue, lem_in->adj_list);
	lem_in->visited[0] = queue_peek(queue);
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
	ft_memdel((void**)&queue);
}

void			find_path(t_lem_in *lem_in)
{
	size_t	k;

	lem_in->visited = ft_memalloc(sizeof(char*) * (lem_in->count_nodes + 1));
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
			unvisit(lem_in, k);
		++k;
	}
}

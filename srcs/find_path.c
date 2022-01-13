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

void			queue_neighbors(t_queue *queue, t_path *pop, t_graph *head)
{
	t_edge	*edge;
	t_graph *node;
	
	edge = pop->node->edges;
	while (edge)
	{
		node = head;
		while (ft_strcmp(node->node_id, edge->dest_id))
			node = node->next;
		enqueue(queue, node, pop->distance + 1);
		edge = edge->next;
	}
}

//TODO
//
//add visited array for queue neighbors
void			find_path(t_lem_in *lem_in)
{
	t_queue		*queue;
	t_path		*pop;
	char		**visited;

	push_start_to_front(lem_in);
	queue = queue_init();
	enqueue(queue, lem_in->adj_list, 0);
	visited = ft_memalloc(sizeof(char*) * (lem_in->count_nodes + 1));
	visited[0] = queue_peek(queue);
	while (!queue_is_empty(queue))
	{
		pop = dequeue(queue);
		if (!ft_strcmp(pop->node->node_id, lem_in->end_id))
		{
			ft_printf("distance %d\n", pop->distance);
			break ;
		}
		queue_neighbors(queue, pop, lem_in->adj_list);
		// 
	}
}

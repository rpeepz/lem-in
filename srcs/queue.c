/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:59:41 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 15:59:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_queue		*queue_init(void)
{
	t_queue	*queue;

	if (!(queue = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

int 		queue_is_empty(t_queue *queue)
{
	return (queue && queue->first ? 0 : 1);
}

char 		*queue_peek(t_queue *queue)
{
	if (queue_is_empty(queue))
		return (NULL);
	return (queue->first->content->node->node_id);
}

void		enqueue(t_queue *queue, t_graph *node, size_t distance)
{
	t_node	*new_node;

	new_node = ft_memalloc(sizeof(new_node));
	new_node->content = ft_memalloc(sizeof(new_node->content));
	new_node->content->node = node;
	new_node->content->distance = distance;
	new_node->next = NULL;
	if (queue_is_empty(queue))
	{
		queue->first = new_node;
		queue->last = queue->first;
	}
	else
	{
		queue->last->next = new_node;
		queue->last = new_node;
	}
}

void		*dequeue(t_queue *queue)
{
	t_node	*pop;
	void	*p;
	
	if (queue_is_empty(queue))
		return (NULL);
	pop = queue->first;
	p = pop->content;
	queue->first = pop->next;
	free(pop);
	return (p);
}

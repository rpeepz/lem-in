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

#include "lemin.h"

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = ft_memalloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

int	queue_is_empty(t_queue *queue)
{
	if (queue && queue->first)
		return (0);
	return (1);
}

void	*queue_peek(t_queue *queue)
{
	if (queue_is_empty(queue))
		return (NULL);
	return (queue->first->content);
}

void	enqueue(t_queue *queue, void *content)
{
	t_node	*new_node;

	new_node = ft_memalloc(sizeof(t_node));
	new_node->content = content;
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

void	*dequeue(t_queue *queue)
{
	t_node	*pop;
	void	*p;

	if (queue_is_empty(queue))
		return (NULL);
	pop = queue->first;
	p = pop->content;
	queue->first = pop->next;
	ft_memdel((void **)&pop);
	return (p);
}

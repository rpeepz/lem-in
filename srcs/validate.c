/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:28:50 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/17 16:18:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>
static void	printgraph(t_lem_in *lem_in)
{
	t_graph	*node;
	t_edge	*edge;

	node = lem_in->adj_list; 
	printf("ants\t%ld\n", lem_in->ants);
	printf("start\t%s\n", lem_in->start_id);
	printf("end\t%s\n", lem_in->end_id);
	printf("nodes\t%ld\n\n", lem_in->count_nodes);
	while (lem_in->adj_list)
	{
		printf("node  %s\n", lem_in->adj_list->node_id);
		edge = lem_in->adj_list->edges;
		while (lem_in->adj_list->edges)
		{
			printf("\tedge-%s\n", lem_in->adj_list->edges->dest_id);
			lem_in->adj_list->edges = lem_in->adj_list->edges->next;
		}
		lem_in->adj_list->edges = edge;
		printf("\n");
		lem_in->adj_list = lem_in->adj_list->next;
	}
	lem_in->adj_list = node;
	if (lem_in->path)
	{
		for (size_t i = 0; i < lem_in->count_nodes; i++)
		{
				printf("path[%ld] = %s\n", i, lem_in->path[i]);
		}
	}
}

int		validate(t_lem_in *lem_in)
{
	if (!lem_in->ants || !lem_in->start_id || !lem_in->end_id ||\
		!lem_in->adj_list || !lem_in->path)
		return (1);
	//testing
	printgraph(lem_in);
	return (0);
}
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
static void	test_print(t_lem_in *lem_in)
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
		for (int i = 0; i < lem_in->count_paths; i++)
		{
			for (int j = 0; j < lem_in->count_nodes; j++)
			{
				printf("path[%ld][%ld] = %s\n", i, j, lem_in->path[i][j]);
			}
			printf("\n");
		}
	}
}

int		validate(t_lem_in *lem_in)
{
	if (!lem_in->ants || !lem_in->start_id || !lem_in->end_id ||\
		!lem_in->adj_list || (lem_in->count_paths && !lem_in->path[0][0]))
		return (1);
	//testing
	test_print(lem_in);
	return (0);
}

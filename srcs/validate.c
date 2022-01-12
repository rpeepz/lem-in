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
static void	printrooms(t_lem_in *lem_in)
{
	t_graph	*node;
	t_edge	*edge;

	node = lem_in->adj_list; 
	printf("ants\t%ld\n", lem_in->ants);
	printf("start\t%s\n", lem_in->start_id);
	printf("end\t%s\n\n", lem_in->end_id);
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
}

void	printfarm(t_farm *farm)
{
	t_farm	*tmp_f;

	if (!farm)
		return ;
	tmp_f = farm;
	printf("\nparent: %s\n", tmp_f->parent ? tmp_f->parent->id : "null parent");
	printf("id:     %s\n", tmp_f->id);
	printf("children:%d\n", tmp_f->child_count);
	for (int i = 0; i < tmp_f->child_count; i++) {
		if (tmp_f->child[i]->parent)
			printfarm(tmp_f->child[i]);
	}
}

int		validate(t_lem_in *lem_in)
{
	if (!(lem_in->ants || lem_in->start_id || lem_in->end_id || lem_in->adj_list))
		return (1);
	printrooms(lem_in);
	printfarm(lem_in->farm);
	return (0);
}
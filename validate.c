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
	t_room	*tmp_r;
	t_link	*tmp_l;

	tmp_r = lem_in->room; 
	printf("ants\t%ld\n", lem_in->ants);
	printf("start\t%s\n", lem_in->start);
	printf("end\t%s\n\n", lem_in->end);
	while (lem_in->room)
	{
		printf("room  %s\n", lem_in->room->id);
		tmp_l = lem_in->room->links;
		while (lem_in->room->links)
		{
			printf("\tlink-%s\n", lem_in->room->links->link);
			lem_in->room->links = lem_in->room->links->next;
		}
		lem_in->room->links = tmp_l;
		printf("\n");
		lem_in->room = lem_in->room->next;
	}
	lem_in->room = tmp_r;
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
	if (!(lem_in->ants || lem_in->start || lem_in->end || lem_in->room))
		return (1);
	printrooms(lem_in);
	printfarm(lem_in->farm);
	return (0);
}
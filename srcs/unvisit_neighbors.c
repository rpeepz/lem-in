/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unvisit_neighbors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:18:45 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/09 20:18:45 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		part_of_path(t_lem_in *lem_in, int i, int k, int *n)
{
	int		p;

	p = 0;
	n[0] = 0;
	while (!p && n[0] <= k)
	{
		n[1] = 0;
		while (!p && lem_in->path[n[0]][n[1]])
		{
			if (!ft_strcmp(lem_in->visited[i], lem_in->path[n[0]][n[1]]))
				p = 1;
			else
				++n[1];
		}
		if (!p)
			++n[0];
	}
	if (n[0] > k)
		--n[0];
}

void			unvisit_neighbors(t_lem_in *lem_in, int k)
{
	int		i;
	int		n[2];

	i = 0;
	while (i < lem_in->count_nodes)
	{
		if (!lem_in->visited[i] ||\
			!ft_strcmp(lem_in->visited[i], lem_in->end_id))
			lem_in->visited[i] = NULL;
		else
		{
			part_of_path(lem_in, i, k, n);
			lem_in->visited[i] = lem_in->path[n[0]][n[1]];
		}
		++i;
	}
}

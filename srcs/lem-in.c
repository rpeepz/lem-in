/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:52:59 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/17 16:17:54 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	die(t_lem_in *lem_in)
{
	t_graph	*graph;
	t_edge	*edge;

	while (lem_in->adj_list)
	{
		graph = lem_in->adj_list->next;
		while (lem_in->adj_list->edges)
		{
			edge = lem_in->adj_list->edges->next;
			ft_memdel((void**)&lem_in->adj_list->edges->dest_id);
			ft_memdel((void**)&lem_in->adj_list->edges);
			lem_in->adj_list->edges = edge;
		}
		ft_memdel((void**)&lem_in->adj_list->node_id);
		ft_memdel((void**)&lem_in->adj_list);
		lem_in->adj_list = graph;
	}
	while (!queue_is_empty(lem_in->queue))
		dequeue(lem_in->queue);
	ft_memdel((void**)&lem_in->queue);
	ft_memdel((void**)&lem_in->start_id);
	ft_memdel((void**)&lem_in->end_id);
	ft_memdel((void**)&lem_in->visited);
	ft_memdel((void**)&lem_in->path);
}

int		get_file(t_lem_in *lem_in)
{
	char	*buf;
	int		err;

	err = 0;
	int fd = open("./maps/subject-3.map", O_RDONLY);
	while ((get_next_line(fd, &buf)) > 0)
	{
		if (!lem_in->ants)
		{	
			if (!ft_isdigit(buf[0]))
				break ;
			lem_in->ants = ft_atoull(buf);
		}
		else if (create_graph(buf, lem_in))
		{
			err = 1;
			break ;
		}
	}
	ft_memdel((void**)&buf);
	return (err);
}

int		main(void)
{
	t_lem_in	lem_in;
	int			err;

	ft_bzero(&lem_in, sizeof(lem_in));
	err = get_file(&lem_in);
	if (err || validate(&lem_in))
		ft_putendl("ERROR");
	else
	{
		graph_undirected(lem_in.adj_list);
		find_path(&lem_in);
		if (validate(&lem_in))
			ft_putendl("ERROR");
		else
			run_ants(&lem_in);
	}
	die(&lem_in);
	return (0);
}

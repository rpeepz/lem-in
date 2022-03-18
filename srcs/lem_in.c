/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:52:59 by rpapagna          #+#    #+#             */
/*   Updated: 2021/02/02 14:21:14 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	die(t_lem_in *lem_in)
{
	t_graph	*graph;
	t_edge	*edge;

	while (lem_in->adj_list)
	{
		graph = lem_in->adj_list->next;
		while (lem_in->adj_list->edges)
		{
			edge = lem_in->adj_list->edges->next;
			ft_memdel((void **)&lem_in->adj_list->edges->dest_id);
			ft_memdel((void **)&lem_in->adj_list->edges);
			lem_in->adj_list->edges = edge;
		}
		ft_memdel((void **)&lem_in->adj_list->node_id);
		ft_memdel((void **)&lem_in->adj_list);
		lem_in->adj_list = graph;
	}
	ft_memdel((void **)&lem_in->file);
	ft_memdel((void **)&lem_in->start_id);
	ft_memdel((void **)&lem_in->end_id);
	ft_memdel((void **)&lem_in->visited);
	path_matrix_destroy(lem_in->path, lem_in->count_paths);
}

static void	save_file(char *buf, t_lem_in *lem_in)
{
	char	*tmp;

	if (!ft_strncmp(buf, START, 7) || !ft_strncmp(buf, END, 5) || \
	(buf[0] && buf[1] && buf[0] != '#' && buf[1] != '#'))
	{
		tmp = ft_strjoin3(lem_in->file, buf, "\n");
		ft_memdel((void **)&lem_in->file);
		lem_in->file = ft_strdup(tmp);
		ft_memdel((void **)&tmp);
	}
}

static int	get_file(t_lem_in *lem_in)
{
	char	*buf;
	int		err;

	err = 0;
	lem_in->file = ft_strdup("");
	while ((get_next_line(0, &buf)) > 0)
	{
		save_file(buf, lem_in);
		if (!(lem_in->ants || buf[0] == '#' || \
			ft_strrchri(buf, ' ') || ft_strrchri(buf, '-')))
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
		ft_memdel((void **)&buf);
	}
	ft_memdel((void **)&buf);
	return (err);
}

int	main(void)
{
	t_lem_in	lem_in;
	int			err;

	ft_bzero(&lem_in, sizeof(lem_in));
	err = get_file(&lem_in);
	if (err || validate(&lem_in))
		ft_putendl("ERROR");
	else
	{
		graph_undirected(&lem_in);
		find_path(&lem_in);
		if (validate(&lem_in))
			ft_putendl("ERROR");
		else
			run_ants(&lem_in);
	}
	die(&lem_in);
	return (0);
}

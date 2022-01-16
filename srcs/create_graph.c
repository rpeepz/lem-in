/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:48:12 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 12:21:35 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	add_adj_list_node(char *line, t_lem_in *lem_in)
{
	char	**buf;
	t_graph	*new_node;
	t_graph	*tmp;

	buf = split_line(line, ' ');
	new_node = ft_memalloc(sizeof(t_graph));
	new_node->node_id = ft_strdup(buf[0]);
	new_node->location.x = (size_t)ft_atoi(buf[1]);
	new_node->location.y = (size_t)ft_atoi(buf[2]);
	tmp = lem_in->adj_list;
	new_node->next = tmp;
	lem_in->adj_list = new_node;
	++lem_in->count_nodes;
	while (*buf)
		free(*(buf)++);
	free(buf);
}

int		create_graph(char *line, t_lem_in *lem_in)
{
	if (ft_strrchri(line, ' ') && (!(line[0] == '#' || line[0] == 'L')))
		add_adj_list_node(line, lem_in);
	if (lem_in->check_start)
	{
		if (lem_in->start_id)
			return (1);
		lem_in->start_id = ft_strndup(line, ft_strchri(line, ' '));
		lem_in->check_start = 0;
	}
	else if (lem_in->check_end)
	{
		if (lem_in->end_id)
			return (1);
		lem_in->end_id = ft_strndup(line, ft_strchri(line, ' '));
		lem_in->check_end = 0;
	}
	else if (!ft_strncmp(line, START, sizeof(START) - 1))
		lem_in->check_start = 1;
	else if (!ft_strncmp(line, END, sizeof(END) - 1))
		lem_in->check_end = 1;
	else if (ft_strrchri(line, '-'))
		add_edge(line, lem_in);
	return (0);
}

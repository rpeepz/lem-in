/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:13:30 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/15 18:13:30 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			path_matrix_destroy(char ***path, size_t cells)
{
	size_t	i;

	i = 0;
	while (i < cells)
	{
		ft_memdel((void**)&path[i]);
		++i;
	}
	ft_memdel((void**)&path);
}

char			***path_matrix_init(size_t cells, size_t rows)
{
	char	***path;
	size_t	i;

	path = ft_memalloc(sizeof(char**) * (cells + 1));
	i = 0;
	while (i < cells)
	{
		path[i] = ft_memalloc(sizeof(char*) * (rows));
		++i;
	}
	return (path);
}

void			path_matrix_save(char ***path, char *neighbor, char *node)
{
	size_t	i;

	i = 0;
	while (path[i] && path[i][0])
		++i;
	path[i][0] = neighbor;
	path[i][1] = node;
}

int				path_matrix_reconstruct(t_lem_in *lem_in)
{
	int		paths_connected;
	size_t	i;
	size_t	j;

	paths_connected = 0;
	lem_in->path = ft_memalloc(sizeof(char*) * (lem_in->count_nodes + 1));
	lem_in->path[0] = lem_in->end_id;
	i = 0;
	while (!paths_connected && ++i < lem_in->count_nodes)
	{
		j = 0;
		while (j < lem_in->count_nodes)
		{
			if (!ft_strcmp(lem_in->path[i - 1], lem_in->prev[j][0]))
			{
				lem_in->path[i] = lem_in->prev[j][1];
				break ;
			}
			++j;
		}
		if (!ft_strcmp(lem_in->path[i], lem_in->start_id))
			paths_connected = 1;
	}
	path_matrix_destroy(lem_in->prev, lem_in->count_nodes);
	return (paths_connected);
}

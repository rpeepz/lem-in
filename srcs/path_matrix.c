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

#include "lemin.h"

void	path_matrix_destroy(char ***path, int cells)
{
	int		i;

	i = 0;
	while (i < cells)
	{
		ft_memdel((void **)&path[i]);
		++i;
	}
	ft_memdel((void **)&path);
}

char	***path_matrix_init(int cells, int rows)
{
	char	***path;
	int		i;

	path = ft_memalloc(sizeof(char **) * (cells + 1));
	i = 0;
	while (i < cells)
	{
		path[i] = ft_memalloc(sizeof(char *) * (rows + 1));
		++i;
	}
	return (path);
}

void	path_matrix_save(char ***path, char *neighbor, char *node)
{
	int		i;

	i = 0;
	while (path[i] && path[i][0])
		++i;
	path[i][0] = neighbor;
	path[i][1] = node;
}

void	path_matrix_reconstruct(t_lem_in *lem_in, int k)
{
	int		i;
	int		j;

	lem_in->path[k][0] = lem_in->end_id;
	i = 1;
	while (i < lem_in->count_nodes && lem_in->path[k][i - 1])
	{
		j = 0;
		while (j < lem_in->count_nodes && lem_in->prev[j][0])
		{
			if (!ft_strcmp(lem_in->path[k][i - 1], lem_in->prev[j][0]))
			{
				lem_in->path[k][i] = lem_in->prev[j][1];
				break ;
			}
			++j;
		}
		++i;
	}
	path_matrix_destroy(lem_in->prev, lem_in->count_nodes);
}

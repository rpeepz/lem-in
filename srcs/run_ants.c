/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:23:22 by rpapagna          #+#    #+#             */
/*   Updated: 2021/02/02 15:21:32 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem-in.h"

static int		**set_path_info(char ***path, int n)
{
	int	**a;
	int		i;
	int		j;

	a = ft_memalloc(sizeof(int*) * n);
	i = 0;
	while (i < n)
	{
		j = 0;
		a[i] = ft_memalloc(sizeof(int) * 2);
		while (path[i][j + 1])
		{
			++a[i][0];
			++j;
		}
		++i;
	}
	return (a);
}

static int		find_best_path(int **path_info, int n)
{
	int		i;
	int		min;

	i = 0;
	min = path_info[i][0] + path_info[i][1];
	while (i < (int)n)
	{
		if (path_info[i][0])
			if ((path_info[i][0] + path_info[i][1]) < min)
				return (i);
		++i;
	}
	return (0);
}

static int		set_ants_in_path(int **path_info, t_lem_in *lem_in)
{
	int		ants;
	int		i;
	int		a;

	ants = (int)(lem_in->ants - 1);
	++path_info[0][1];
	while (ants)
	{
		i = find_best_path(path_info, lem_in->count_paths);
		path_info[i][1] += 1;
		--ants;
	}
	i = 0;
	a = 0;
	while (i < (int)lem_in->count_paths)
	{
		if (path_info[i][1])
			++a;
		++i;
	}
	return (a);
}

void			move_ants(int **path_info, t_lem_in *lem_in, int n, int ant)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 1;
	while (ant + i + n > 0)
	{
		ant -= n;
		i = 0;
		x = j;
		while (i < (int)lem_in->ants && (ant + i) < (int)lem_in->ants)
		{
			if (i && (i % n == 0))
				x = j - (i / n);
			if (x <= path_info[i % n][0] && lem_in->path[i % n][x])
				printf("L%d-%s ", i + 1, lem_in->path[i % n][x]);
			++i;
		}
		++j;
		printf("\n");
		// printf("(i = %d)", i);
		// printf("(j = %d)", j);
		// printf("(x = %d)", x);
		// printf("(ant = %d)", ant);
		// printf("(n = %d)", n);
	}
}

void			run_ants(t_lem_in *lem_in)
{
	int		**path_info;
	int		n;
	int		i;
// lem_in->ants = 22;
	path_info = set_path_info(lem_in->path, lem_in->count_paths);
	n = set_ants_in_path(path_info, lem_in);
	printf("%s\n", lem_in->file);
	move_ants(path_info, lem_in, n, (int)lem_in->ants);
	i = 0;
	while (i < (int)lem_in->count_paths)
	{
		ft_memdel((void**)&path_info[i]);
		++i;
	}
	ft_memdel((void**)&path_info);
}

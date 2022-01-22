/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:23:22 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/17 15:23:22 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static size_t	**count_path_steps(char ***path, size_t n)
{
	size_t	**a;
	size_t	i;
	size_t	j;

	a = ft_memalloc(sizeof(size_t*) * n);
	i = 0;
	while (i < n)
	{
		j = 0;
		a[i] = ft_memalloc(sizeof(size_t) * 2);
		while (path[i][j + 1])
		{
			++a[i][0];
			++j;
		}
		++i;
	}
	return (a);
}

static size_t	find_best_path(size_t **path_steps, size_t n)
{
	size_t	i;
	size_t	min;

	i = 0;
	min = path_steps[i][0] + path_steps[i][1];
	while (i < n)
	{
		if (path_steps[i][0])
			if ((path_steps[i][0] + path_steps[i][1]) < min)
				return (i);
		++i;
	}
	return (0);
}

static void		set_ants_in_path(size_t **path_steps, t_lem_in *lem_in)
{
	size_t	ants;
	size_t	i;

	ants = (lem_in->ants - 1);
	++path_steps[0][1];
	while (ants)
	{
		i = find_best_path(path_steps, lem_in->count_paths);
		path_steps[i][1] += 1;
		--ants;
	}
}
#include<stdio.h>
void			run_ants(t_lem_in *lem_in)
{
	size_t		**path_steps;
	size_t		i;

	path_steps = count_path_steps(lem_in->path, lem_in->count_paths);
	set_ants_in_path(path_steps, lem_in);

	//testing
	{
		printf("%ld ants\n", lem_in->ants);
		for (size_t i = 0; i < lem_in->count_paths; i++) {
			printf("path_steps[%ld][0] = %ld (steps in path)\n", i, path_steps[i][0]);
			printf("path_steps[%ld][1] = %ld (ants in path)\n", i, path_steps[i][1]);
		}
		printf("\n");
	}

	//print running ants
	{
		for (size_t i = 0; i < lem_in->count_paths; i++) {
			printf("%ld (steps in path)\n", path_steps[i][0]);
			printf("%ld (ants in path)\n", path_steps[i][1]);
		}
		printf("\n");
	}
	//free `path_steps`
	{
		i = 0;
		while (i < lem_in->count_paths)
		{
			ft_memdel((void**)&path_steps[i]);
			++i;
		}
	}

	ft_memdel((void**)&path_steps);
}

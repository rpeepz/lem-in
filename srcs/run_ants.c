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

size_t		**count_path_steps(char ***path, size_t n)
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

void		set_ants_in_path(size_t **path_steps, t_lem_in *lem_in)
{
	size_t	ants;
	size_t	i;

	ants = (lem_in->ants - 1);
	i = 0;
	++path_steps[i][1];
	while (ants)
	{
		--ants;
	}
}
#include<stdio.h>
void		run_ants(t_lem_in *lem_in)
{
	size_t		**path_steps;
	size_t		i;

	path_steps = count_path_steps(lem_in->path, lem_in->count_paths);

	//testing
	{
		printf("%ld ants\n", lem_in->ants);
		for (size_t i = 0; i < lem_in->count_paths; i++) {
			printf("path_steps[%ld][0] = %ld\n", i, path_steps[i][0]);
			printf("path_steps[%ld][1] = %ld\n", i, path_steps[i][1]);
		}
		printf("\n");
	}

	set_ants_in_path(path_steps, lem_in);

	//testing
	{
		printf("%ld ants\n", lem_in->ants);
		for (size_t i = 0; i < lem_in->count_paths; i++) {
			printf("path_steps[%ld][0] = %ld\n", i, path_steps[i][0]);
			printf("path_steps[%ld][1] = %ld\n", i, path_steps[i][1]);
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

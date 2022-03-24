/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:42:29 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/08 20:42:29 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
*	create n int arrays, where n is the number of valid paths
*
*	each int array has 2 indices:
*	[0] = total steps in path
*	[1] = total ants to flow in path
*/
int	**set_path_info(char ***path, int n)
{
	int		**a;
	int		i;
	int		j;

	a = ft_memalloc(sizeof(int *) * n);
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

/*
*	use a min differential to find optimal ant placement from the given paths
*/
static int	find_best_path(int **path_info, int n)
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

/*
*	assign a path to each ant
*	returns the number of concurent ants to flow
*/
int	set_ants_in_path(int **path_info, t_lem_in *lem_in)
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

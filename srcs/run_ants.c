/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:23:22 by rpapagna          #+#    #+#             */
/*   Updated: 2021/02/04 13:03:32 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		**ant_farm(int n)
{
	int		**a;
	int		i;

	a = ft_memalloc(sizeof(int*) * n);
	i = 0;
	while (i < n)
	{
		a[i] = ft_memalloc(sizeof(int) * 2);
		++i;
	}
	return (a);
}

static void		ant_continue(t_lem_in *lem_in, int **farm)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < lem_in->ants)
	{
		if (farm[i][1] > 0)
		{
			if (p)
				ft_putchar(' ');
			++farm[i][1];
			print_movement(i + 1, lem_in->path[farm[i][0]][farm[i][1]]);
			p = 1;
			if (lem_in->path[farm[i][0]][farm[i][1]] == lem_in->end_id)
				farm[i][1] = -1;
		}
		++i;
	}
}

static void		ant_start(t_lem_in *lem_in, int **farm, int **path_info, int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		if (path_info[i][1])
		{
			j = -1;
			while (++j < lem_in->ants)
			{
				if (farm[j][1] == 0)
				{
					if (j)
						ft_putchar(' ');
					--path_info[i][1];
					farm[j][0] = i;
					farm[j][1] = 1;
					print_movement(j + 1, lem_in->path[farm[j][0]][farm[j][1]]);
					break ;
				}
			}
		}
	}
}

static void		move_ants(int **path_info, t_lem_in *lem_in, int n)
{
	int		**farm;
	int		i;
	
	farm = ant_farm(lem_in->ants);
	i = 0;
	while (!i || continue_movement(farm, lem_in->ants))
	{
		i = 1;
		ant_continue(lem_in, farm);
		ant_start(lem_in, farm, path_info, n);
		ft_putchar('\n');
	}
	i = 0;
	while (i < lem_in->ants)
	{
		ft_memdel((void**)&farm[i]);
		++i;
	}
	ft_memdel((void**)&farm);
}

void			run_ants(t_lem_in *lem_in)
{
	int		**path_info;
	int		n;
	int		i;

	path_info = set_path_info(lem_in->path, lem_in->count_paths);
	n = set_ants_in_path(path_info, lem_in);
	print_file(lem_in->file);
	move_ants(path_info, lem_in, n);
	i = 0;
	while (i < (int)lem_in->count_paths)
	{
		ft_memdel((void**)&path_info[i]);
		++i;
	}
	ft_memdel((void**)&path_info);
}

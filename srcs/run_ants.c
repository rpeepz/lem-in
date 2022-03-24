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

#include "lemin.h"

static int	**ant_farm(int n)
{
	int		**a;
	int		i;

	a = ft_memalloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		a[i] = ft_memalloc(sizeof(int) * 2);
		++i;
	}
	return (a);
}

static int	ant_continue(t_lem_in *lem_in, int **farm)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < lem_in->ants)
	{
		if (farm[i][1] == -1 || \
			lem_in->path[farm[i][0]][farm[i][1]] == lem_in->end_id)
			farm[i][1] = -1;
		if (farm[i][1] > 0)
		{
			if (p)
				ft_putchar(' ');
			++farm[i][1];
			print_movement(i + 1, lem_in->path[farm[i][0]][farm[i][1]]);
			p = 1;
		}
		++i;
	}
	return (p);
}

static void	ant_start(t_lem_in *lem_in, t_solution *s, int t)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s->n)
	{
		if (s->path_info[i][1])
		{
			j = -1;
			while (++j < lem_in->ants)
			{
				if (s->farm[j][1] == 0)
				{
					if (i || t)
						ft_putchar(' ');
					--(s->path_info[i][1]);
					s->farm[j][0] = i;
					s->farm[j][1] = 1;
					print_movement(j + 1, \
					lem_in->path[s->farm[j][0]][s->farm[j][1]]);
					break ;
				}
			}
		}
	}
}

static void	move_ants(t_lem_in *lem_in, t_solution *s)
{
	int	i;
	int	t;

	s->farm = ant_farm(lem_in->ants);
	i = 0;
	while (!i || continue_movement(s->farm, lem_in->ants))
	{
		t = ant_continue(lem_in, s->farm);
		ant_start(lem_in, s, t);
		ft_putchar('\n');
		i = 1;
	}
	i = 0;
	while (i < lem_in->ants)
	{
		ft_memdel((void **)&s->farm[i]);
		++i;
	}
	ft_memdel((void **)&s->farm);
}

void	run_ants(t_lem_in *lem_in)
{
	t_solution	s;
	int			i;

	s.path_info = set_path_info(lem_in->path, lem_in->count_paths);
	s.n = set_ants_in_path(s.path_info, lem_in);
	print_file(lem_in->file);
	move_ants(lem_in, &s);
	i = 0;
	while (i < (int)lem_in->count_paths)
	{
		ft_memdel((void **)&s.path_info[i]);
		++i;
	}
	ft_memdel((void **)&s.path_info);
}

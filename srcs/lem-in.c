/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:52:59 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/17 16:17:54 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	die(t_lem_in *lem_in)
{
	t_room	*tmp_r;
	t_link	*tmp_l;

	while (lem_in->room)
	{
		tmp_r = lem_in->room->next;
		while (lem_in->room->links)
		{
			tmp_l = lem_in->room->links->next;
			ft_memdel((void**)&lem_in->room->links->link);
			ft_memdel((void**)&lem_in->room->links);
			lem_in->room->links = tmp_l;
		}
		ft_memdel((void**)&lem_in->room->id);
		ft_memdel((void**)&lem_in->room);
		lem_in->room = tmp_r;
	}
	ft_memdel((void**)&lem_in->start);
	ft_memdel((void**)&lem_in->end);
}

int		assign_farm(char *line, t_lem_in *lem_in)
{
	if (ft_strrchri(line, ' ') && (!(line[0] == '#' || line[0] == 'L')))
		build_room(line, lem_in);
	if (lem_in->check_start)
	{
		if (lem_in->start)
			return (1);
		lem_in->start = ft_strndup(line, ft_strchri(line, ' '));
		lem_in->check_start = 0;
	}
	else if (lem_in->check_end)
	{
		if (lem_in->end)
			return (1);
		lem_in->end = ft_strndup(line, ft_strchri(line, ' '));
		lem_in->check_end = 0;
	}
	else if (!ft_strncmp(line, START, sizeof(START) - 1))
		lem_in->check_start = 1;
	else if (!ft_strncmp(line, END, sizeof(END) - 1))
		lem_in->check_end = 1;
	else if (ft_strrchri(line, '-'))
		build_link(line, lem_in);
	return (0);
}

int		get_file(t_lem_in *lem_in)
{
	char	*buf;
	int		err;

	err = 0;
	int fd = open("./maps/has_comments.map", O_RDONLY);
	while ((get_next_line(fd, &buf)) > 0)
	{
		if (!lem_in->ants)
		{	
			if (!ft_isdigit(buf[0]))
				break ;
			lem_in->ants = ft_atoull(buf);
		}
		else if (assign_farm(buf, lem_in))
		{
			err = 1;
			break ;
		}
	}
	ft_memdel((void**)&buf);
	return (err);
}

int		main(void)
{
	t_lem_in	lem_in;
	int			err;

	ft_bzero(&lem_in, sizeof(lem_in));
	err = get_file(&lem_in);
	if (err || validate(&lem_in))
		ft_putendl("ERROR");
	else
	{
		build_tree(&lem_in);
		validate(&lem_in);
		run_ants(&lem_in);
	}
	die(&lem_in);
	return (0);
}

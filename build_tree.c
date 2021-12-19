/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:26:23 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/18 19:12:29 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		push_start_to_front(t_lem_in *lem_in)
{
	t_room	*head;
	t_room	*prev;
	t_room	*tmp;

	head = lem_in->room;
	while (ft_strcmp(lem_in->start, lem_in->room->id))
	{
		prev = lem_in->room;
		lem_in->room = lem_in->room->next;
	}
	prev->next = lem_in->room->next;
	tmp = head;
	lem_in->room->next = tmp;
}

static t_farm	*check_parents(t_farm *head, t_farm* parent, t_link *link)
{
	int		i;
	int		j;
	t_farm	*farm;
	t_link	*tmp_l;

	farm = head;
	if (farm)
	{
		i = -1;
		while (++i < farm->child_count)
		{
			tmp_l = link;
			while (tmp_l)
			{
				if (!ft_strcmp(farm->id, tmp_l->link))
					return (farm);
				tmp_l = tmp_l->next;
			}
		}
		j = -1;
		while (++j < farm->child_count)
			return (check_parents(farm->child[j], parent, link));
	}
	return (NULL);
}

static void		create_children(t_farm *head, t_farm *parent, t_link *link)
{
	int		n;
	t_link	*tmp_l;
	t_farm	*farm;

	n = 0;
	tmp_l = link;
	while (n < parent->child_count)
	{
		farm = check_parents(head, parent, link);
		if (farm)
			parent->child[n] = farm;
		else
		{
			parent->child[n] = (t_farm*)ft_memalloc(sizeof(*parent->child[n]));
			parent->child[n]->id = ft_strdup(tmp_l->link);
			parent->child[n]->parent = parent;
		}
		tmp_l = tmp_l->next;
		++n;
	}
}

static void		count_links(t_farm *parent, t_room *room)
{
	t_link	*links;

	if (parent->child_count)
		return ;
	links = room->links;
	while (links)
	{
		++parent->child_count;
		links = links->next;
	}
	parent->child =\
	(t_farm**)ft_memalloc(sizeof(*parent->child) * (parent->child_count + 1));
}

static void		assign_tree(t_farm *head, int n, t_farm **kids, t_room *rooms)
{
	t_room	*room;
	t_farm	*child;
	t_farm	**children;
	int		i;

	i = -1;
	while (++i < n)
	{
		child = kids[i];
		if (child->child_count)
			continue ;
		room = rooms;
		while (ft_strcmp(child->id, room->id))
			room = room->next;
		count_links(child, room);
		create_children(head, child, room->links);
		children = child->child;
		assign_tree(head, child->child_count, children, rooms);
	}
}

void			build_tree(t_lem_in *lem_in)
{
	t_farm	*farm;

	push_start_to_front(lem_in);
	farm = (t_farm*)ft_memalloc(sizeof(*farm));
	farm->id = ft_strdup(lem_in->room->id);
	farm->parent = NULL;
	lem_in->farm = farm;
	count_links(farm, lem_in->room);
	create_children(farm, farm, lem_in->room->links);
	assign_tree(farm, farm->child_count, farm->child, lem_in->room);
}

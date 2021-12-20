/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:12:32 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/18 19:11:56 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		word_len(char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		++i;
	while (s[i] && s[i] != c)
	{
		++i;
		++len;
	}
	return (len);
}

static char		**split_line(char *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		n;
	
	n = ft_countwords(s, c);
	arr = ft_memalloc(sizeof(*arr) * (n + 1));
	i = 0;
	j = 0;
	while (i < n)
	{
		arr[i] = ft_strsub(s, j, word_len(&s[j], c));
		if (ft_strchri(arr[i], '\r') > 0)
			arr[i][ft_strchri(arr[i], '\r')] = '\0';
		j += ft_strlen(arr[i]) + 1;
		++i;
	}
	arr[i] = NULL;
	return (arr);
}

void			build_room(char *line, t_lem_in *lem_in)
{
	char	**buf;
	t_room	*new_room;
	t_room	*tmp;

	buf = split_line(line, ' ');
	new_room = ft_memalloc(sizeof(*new_room));
	new_room->id = ft_strdup(buf[0]);
	new_room->location.x = (size_t)ft_atoi(buf[1]);
	new_room->location.y = (size_t)ft_atoi(buf[2]);
	tmp = lem_in->room;
	new_room->next = tmp;
	lem_in->room = new_room;
	while (*buf)
		free(*(buf)++);
	free(buf);
}

void			build_link(char *line, t_lem_in *lem_in)
{
	char	**buf;
	t_link	*new_link;
	t_room	*tmp_r;
	t_link	*tmp_l;

	buf = split_line(line, '-');
	new_link = ft_memalloc(sizeof(*new_link));
	new_link->link = ft_strdup(buf[1]);
	tmp_r = lem_in->room;
	while (tmp_r)
	{
		if (!ft_strcmp(tmp_r->id, buf[0]))
		{
			tmp_l = tmp_r->links;
			new_link->next = tmp_l;
			tmp_r->links = new_link;
			break ;
		}
		tmp_r = tmp_r->next;
	}
	while (*buf)
		free(*(buf)++);
	free(buf);
}

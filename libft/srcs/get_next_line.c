/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:10:19 by rpapagna          #+#    #+#             */
/*   Updated: 2022/03/13 18:52:26 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int	ft_afterline(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = -1;
	while (s[fd][++len])
		if (s[fd][len] == '\n')
			break ;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = ft_strdup(tmp);
		free(tmp);
		if (s[fd][0] == '\0')
			ft_strclr(s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		*s[fd] = 0;
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*str[MAX_FD];
	char			*tmp;
	char			buf[GNL_BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	i = read(fd, buf, GNL_BUFF_SIZE);
	while (i > 0)
	{
		if (!str[fd])
			str[fd] = ft_strnew(0);
		buf[i] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
		i = read(fd, buf, GNL_BUFF_SIZE);
	}
	if (!i && (!str[fd] || (!(*str[fd]))))
		return (0);
	return (ft_afterline(str, line, fd));
}

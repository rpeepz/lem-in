/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:08:02 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:08:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_whitespace(char *str, size_t *i, size_t *j)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r' || \
		str[*i] == '\f' || str[*i] == '\n' || *i > ft_strlen(str))
		(*i)++;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r' || \
		str[*i] == '\f' || str[*j] == '\n')
		(*j)--;
	if (*i || *j < ft_strlen(str))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	new_len;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	if (!has_whitespace((char *)s, &start, &end))
		return (ft_strdup(s));
	if (start == ft_strlen(s))
		new_len = 0;
	else
		new_len = ft_strlen(s) - start - (ft_strlen(s) - end);
	new = ft_strnew(new_len + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, &s[start], new_len + 1);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:05:05 by rpapagna          #+#    #+#             */
/*   Updated: 2022/03/13 16:24:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}

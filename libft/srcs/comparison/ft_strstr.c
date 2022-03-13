/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:58:06 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:07:25 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	int		match;

	if (!*needle)
		return ((char *)haystack);
	i = -1;
	match = 0;
	while (haystack[++i] && !match)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			tmp = i;
			match = 1;
			while (needle[j])
				if (needle[j++] != (haystack[tmp++]))
					match = 0;
			if (match)
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:07:10 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:07:10 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	int		match;

	i = -1;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while ((haystack[++i]) && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			tmp = i;
			match = 1;
			while (haystack[tmp] && needle[j] && j < len && tmp < len)
				if (haystack[tmp++] != needle[j++])
					match = 0;
			if (match && !needle[j])
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}

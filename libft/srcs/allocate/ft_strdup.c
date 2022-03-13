/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:15:59 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:15:59 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1) + 1;
	dup = (char *)malloc(i);
	if (!dup)
		return (NULL);
	dup[--i] = '\0';
	while (i-- > 0)
		dup[i] = s1[i];
	return (dup);
}

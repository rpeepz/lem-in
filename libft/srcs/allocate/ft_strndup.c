/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:16:06 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:16:06 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len-- > 0)
		dup[len] = s[len];
	return (dup);
}

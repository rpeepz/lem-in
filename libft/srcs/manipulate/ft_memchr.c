/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:38:24 by rpapagna          #+#    #+#             */
/*   Updated: 2022/03/13 16:24:23 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	asc;
	size_t			i;

	str = (unsigned char *)s;
	asc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (asc == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

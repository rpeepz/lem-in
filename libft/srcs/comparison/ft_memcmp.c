/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:45:54 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:45:54 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (i < n && one[i] == two[i])
		i++;
	if (i == n)
		return (0);
	return (one[i] - two[i]);
}

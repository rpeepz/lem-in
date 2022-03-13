/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:32:25 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:32:25 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	performs big endian output of hex
*/

unsigned long long	ft_hextoull(const char *str)
{
	int					i;
	unsigned long long	n;
	unsigned long long	val;

	n = 0;
	if (!str)
		return (n);
	i = 0;
	while (i < 16 && str[i])
	{
		if (ft_isdigit(str[i]))
			val = (str[i] - '0');
		else if (ft_toupper(str[i]) >= 'A' && ft_toupper(str[i]) <= 'F')
			val = (ft_toupper(str[i]) - '7');
		n |= val << (60 - (i * 4));
		i++;
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_eq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:20:17 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:47:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

int	bignum_eq(t_bignum *n1, t_bignum *n2)
{
	size_t	i;
	size_t	len;

	if (n1->sign == n2->sign && n1->len == n2->len)
	{
		i = 0;
		len = n1->len;
		while (i < len)
		{
			if (n1->number[i] != n2->number[i])
				break ;
			++i;
		}
		if (i == len)
			return (0);
	}
	return (1);
}

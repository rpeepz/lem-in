/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:56:06 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:39:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

int	return_value(int sign, int type, int ret)
{
	if (ret == 0)
	{
		if (sign == type)
			return (0);
		return (1);
	}
	if (sign == type)
		return (1);
	return (0);
}

int	bignum_compare(t_bignum *n1, t_bignum *n2, int type)
{
	size_t	i;

	if (n1->sign == type && n2->sign != type)
		return (0);
	if ((n1->sign != type && n2->sign == type) || !bignum_eq(n1, n2))
		return (1);
	if (n1->len > n2->len)
		return (return_value(n1->sign, type, 0));
	if (n1->len < n2->len)
		return (return_value(n1->sign, type, 1));
	i = 0;
	while (i < n1->len)
	{
		if (n1->number[i] == n2->number[i])
			++i;
		else if (n1->number[i] > n2->number[i])
			return (return_value(n1->sign, type, 0));
		else
			return (return_value(n1->sign, type, 1));
	}
	return (0);
}

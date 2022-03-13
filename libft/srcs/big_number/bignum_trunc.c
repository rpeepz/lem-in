/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_trunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:38:40 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:55:46 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

t_bignum	*bignum_trunc(t_bignum *bignum)
{
	size_t	i;
	size_t	j;

	if (bignum->len > 1)
	{
		i = bignum->sign;
		j = bignum->sign;
		while (bignum->number[i] == '0')
			++i;
		if (i == bignum->alloc_size)
		{
			++j;
			++i;
			bignum->number[j] = '\0';
		}
		while (i <= bignum->alloc_size && i)
			bignum->number[j++] = bignum->number[i++];
		if (j)
			bignum->len = j - 1;
	}
	return (bignum);
}

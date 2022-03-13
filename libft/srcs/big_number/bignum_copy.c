/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:39:38 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:45:34 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

t_bignum	*bignum_copy(t_bignum *dst, t_bignum *src)
{
	size_t	i;

	i = src->len;
	if (i > dst->alloc_size)
	{
		free(dst->number);
		dst->alloc_size = i;
		dst->number = (char *)malloc(sizeof(char) * (i + 1));
	}
	dst->len = i;
	dst->number[i] = '\0';
	while (i > 0)
	{
		--i;
		dst->number[i] = src->number[i];
	}
	dst->sign = src->sign;
	return (dst);
}

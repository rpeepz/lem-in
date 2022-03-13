/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:28:15 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:55:25 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

void	bignum_swap(t_bignum *a, t_bignum *b)
{
	char	*tmp_num;
	size_t	tmp;
	int		tmp_sign;

	tmp = a->alloc_size;
	a->alloc_size = b->alloc_size;
	b->alloc_size = tmp;
	tmp = a->len;
	a->len = b->len;
	b->len = tmp;
	tmp_num = a->number;
	a->number = b->number;
	b->number = tmp_num;
	tmp_sign = a->sign;
	a->sign = b->sign;
	b->sign = tmp_sign;
}

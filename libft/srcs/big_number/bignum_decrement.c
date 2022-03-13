/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_decrement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:07:33 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/26 13:46:03 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

t_bignum	*bignum_decrement(t_bignum *n)
{
	t_bignum	*res;
	t_bignum	*one;

	one = bignum_init("1");
	res = bignum_minus(n, one);
	bignum_swap(n, res);
	bignum_del(&one);
	bignum_del(&res);
	return (n);
}

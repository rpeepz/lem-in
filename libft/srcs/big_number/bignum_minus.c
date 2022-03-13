/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:53:16 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 14:12:35 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

t_bignum	*bignum_minus(t_bignum *m, t_bignum *s)
{
	if (m->sign == s->sign)
		return (bignum_add_neg(m, s, 1, 0));
	return (bignum_add_neg(m, s, 0, 0));
}

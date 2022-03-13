/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_quotient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:46:23 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:41:30 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

static t_bignum	*find_quotient(t_bignum *divisor, t_bignum *bignum_id, \
									t_bignum *remainder, char *quotient)
{
	t_bignum	*tmp;
	t_bignum	*d;
	int			found;

	d = bignum_init("1");
	found = 0;
	while (!found)
	{
		tmp = bignum_multiply(divisor, d);
		if (!bignum_gt(tmp, bignum_id))
		{
			found = 1;
			bignum_decrement(d);
			bignum_del(&tmp);
			tmp = bignum_multiply(divisor, d);
			remainder = bignum_minus(bignum_id, tmp);
		}
		else
			bignum_increment(d);
		bignum_del(&tmp);
	}
	ft_strcat(quotient, d->number);
	bignum_del(&d);
	return (remainder);
}

t_bignum	*do_quotient(t_bignum *dividend, t_bignum *divisor, \
								t_bignum *remainder, char *quotient)
{
	size_t		k;
	size_t		l;
	size_t		i;
	char		*idividend;
	t_bignum	*b_idividend;

	k = dividend->len;
	l = divisor->len - 1;
	i = 0;
	idividend = ft_memalloc(divisor->len + 1);
	while (i < k - l)
	{
		ft_bzero(idividend, divisor->len + 1);
		ft_strcat(idividend, remainder->number);
		bignum_del(&remainder);
		ft_strncat(idividend, dividend->number + (l + i), 1);
		b_idividend = bignum_init(idividend);
		remainder = find_quotient(divisor, b_idividend, remainder, quotient);
		bignum_del(&b_idividend);
		++i;
	}
	ft_memdel((void **)&idividend);
	return (remainder);
}

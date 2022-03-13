/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:09 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:47:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

static t_bignum	*do_divide(t_bignum *d1, t_bignum *d2, \
					t_bignum *dividend, t_bignum *divisor)
{
	char		*quotient;
	t_bignum	*remainder;
	t_bignum	*bignum_quotient;

	dividend = bignum_init(d1->number + d1->sign);
	divisor = bignum_init(d2->number + d2->sign);
	if (dividend->len < divisor->len)
	{
		bignum_del(&dividend);
		bignum_del(&divisor);
		return (bignum_init("0"));
	}
	remainder = init_remainder(dividend->number, divisor->len);
	quotient = (char *)malloc(sizeof(char) * (d2->len + 2));
	ft_bzero(quotient, d2->len + 1);
	if (d1->sign ^ d2->sign)
		quotient[0] = '-';
	remainder = do_quotient(dividend, divisor, remainder, quotient);
	bignum_del(&remainder);
	bignum_quotient = bignum_init(quotient);
	free(quotient);
	bignum_del(&dividend);
	bignum_del(&divisor);
	return (bignum_quotient);
}

static t_bignum	*return_value(t_bignum *d1, t_bignum *d2, \
								t_bignum *n1, t_bignum *n2)
{
	if (n1)
		return (n1);
	return (do_divide(d1, d2, n1, n2));
}

t_bignum	*bignum_divide(t_bignum *d1, t_bignum *d2)
{
	t_bignum	*check;
	t_bignum	*n1;
	t_bignum	*n2;

	n1 = NULL;
	n2 = NULL;
	check = bignum_init("0");
	if (!bignum_eq(d2, check))
	{
		ft_putendl_fd("Error: Divide by zero", 2);
		n1 = bignum_init("0");
	}
	if (!bignum_eq(d1, check))
		n1 = bignum_init("0");
	check = bignum_increment(check);
	if (!bignum_eq(d2, check))
		n1 = bignum_init(d1->number);
	check = bignum_decrement(check);
	check = bignum_decrement(check);
	if (!bignum_eq(d2, check))
		n1 = bignum_multiply(d1, check);
	bignum_del(&check);
	return (return_value(d1, d2, n1, n2));
}

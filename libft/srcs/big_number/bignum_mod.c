/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:59:04 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:53:57 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

static void	bignum_neg(t_bignum *a)
{
	t_bignum	*b;
	t_bignum	*res;

	b = bignum_init("-1");
	res = bignum_multiply(a, b);
	bignum_swap(a, res);
	bignum_del(&b);
	bignum_del(&res);
}

static t_bignum	*do_mod(t_bignum *d1, t_bignum *d2, \
						t_bignum *dividend, t_bignum *divisor)
{
	char		*quotient;
	t_bignum	*remainder;

	dividend = bignum_init(d1->number + d1->sign);
	divisor = bignum_init(d2->number + d2->sign);
	if (dividend->len < divisor->len)
	{
		bignum_del(&dividend);
		bignum_del(&divisor);
		return (bignum_init(d1->number));
	}
	remainder = init_remainder(dividend->number, divisor->len);
	quotient = (char *)malloc(sizeof(char) * (d2->len + 2));
	ft_bzero(quotient, d2->len + 1);
	remainder = do_quotient(dividend, divisor, remainder, quotient);
	bignum_del(&dividend);
	bignum_del(&divisor);
	free(quotient);
	if (d1->sign)
		bignum_neg(remainder);
	return (remainder);
}

static t_bignum	*return_value(t_bignum *d1, t_bignum *d2, \
								t_bignum *n1, t_bignum *n2)
{
	if (n1)
		return (n1);
	return (do_mod(d1, d2, n1, n2));
}

t_bignum	*bignum_mod(t_bignum *d1, t_bignum *d2)
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
	if (!bignum_eq(d1, check))
	{
		if (!bignum_eq(d1, d2))
			n1 = bignum_init("0");
		else
			n1 = bignum_init("1");
	}
	bignum_del(&check);
	return (return_value(d1, d2, n1, n2));
}

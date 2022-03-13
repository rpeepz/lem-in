/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:23 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:54:55 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

static char	do_product(char m1, char m2)
{
	if (m1 == '0' || m2 == '0' || m1 == '-' || m2 == '-')
		return (0);
	else
		return ((m1 - '0') * (m2 - '0'));
}

static t_bignum	*do_work(t_bignum *n1, t_bignum *n2, char *result, size_t k)
{
	size_t	i;
	size_t	j;
	size_t	idx_r;
	size_t	idx_a;

	init_result(result, k, (n1->sign ^ n2->sign));
	i = n1->len;
	idx_r = (n1->len + n2->len) - 2;
	while (!(i == 0 && j == 0))
	{
		--i;
		j = n2->len;
		while (j != 0)
		{
			--j;
			idx_a = k - 1 - (idx_r - (i + j));
			result[idx_a] += do_product(n1->number[i], n2->number[j]);
			while (result[idx_a] > '9' || result[idx_a] < '0')
			{
				result[idx_a] -= 10;
				result[idx_a - 1] += 1;
			}
		}
	}
	return (bignum_init(result));
}

t_bignum	*bignum_multiply(t_bignum *m1, t_bignum *m2)
{
	size_t		k;
	char		*result;
	t_bignum	*product;

	k = m1->len + m2->len + 1;
	product = bignum_init("0");
	if (!bignum_eq(m1, product) || !bignum_eq(m2, product))
		return (product);
	bignum_del(&product);
	result = (char *)malloc(sizeof(char) * (k + 1));
	product = do_work(m1, m2, result, k);
	free(result);
	return (bignum_trunc(product));
}

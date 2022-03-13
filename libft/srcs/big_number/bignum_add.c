/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:16:03 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 14:19:37 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

static t_bignum	*do_work(t_bignum *n1, t_bignum *n2, char *result, size_t k)
{
	size_t	i;
	size_t	j;

	init_result(result, k, (int)n1->sign);
	i = n1->len;
	j = n2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		result[k] += do_sum(&i, &j, n1->number, n2->number);
		carry(result, k, 0);
	}
	return (bignum_init(result));
}

t_bignum	*bignum_add(t_bignum *a1, t_bignum *a2)
{
	size_t		k;
	char		*result;
	t_bignum	*sum;

	if (a1->sign != a2->sign)
		return (bignum_add_neg(a1, a2, 1, 0));
	if (a1->len > a2->len)
		k = 1 + a1->len;
	else
		k = 1 + a2->len;
	result = (char *)malloc(sizeof(char) * (k + 1));
	sum = do_work(a1, a2, result, k);
	free(result);
	return (bignum_trunc(sum));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:16:32 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:49:09 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

static int	bignum_init_eval(char *n)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(n);
	if (n[i] == '-' && ft_isdigit(n[i + 1]))
		++i;
	if (!n[i])
		return (0);
	while (i < len)
	{
		if (n[i] >= '0' && n[i] <= '9')
			++i;
		else
			break ;
	}
	return (i);
}

t_bignum	*properties(t_bignum *a, char *number)
{
	if (*number == '-')
		a->sign = 1;
	else
		a->sign = 0;
	a->len = bignum_init_eval(number);
	return (a);
}

t_bignum	*bignum_init(char *number)
{
	t_bignum	*a;
	size_t		i;

	if (!number)
		return (NULL);
	a = (t_bignum *)malloc(sizeof(t_bignum));
	a = properties(a, number);
	i = ft_strncmp(number, "-0", a->len);
	if (!a->len || !i || i > '9')
	{
		a->sign = 0;
		a->len = 1;
		number = "0";
	}
	a->alloc_size = a->len;
	a->number = (char *)malloc(a->alloc_size + 1);
	i = 0;
	while (i < a->alloc_size)
	{
		a->number[i] = number[i];
		++i;
	}
	a->number[i] = '\0';
	return (bignum_trunc(a));
}

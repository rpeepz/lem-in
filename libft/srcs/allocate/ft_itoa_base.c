/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:44:14 by rpapagna          #+#    #+#             */
/*   Updated: 2022/03/13 18:43:12 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	g_base[] = "0123456789ABCDEF";

char	*assign(char *str, int tmp, int len, int base)
{
	while (len--)
	{
		str[len] = g_base[(tmp % base)];
		tmp /= base;
	}
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	int		tmp;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n *= -1;
	tmp = n;
	len = 1;
	while (tmp / base)
	{
		tmp /= base;
		len++;
	}
	tmp = n;
	if (base == 10)
		len += 1;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = assign(str, tmp, len, base);
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}

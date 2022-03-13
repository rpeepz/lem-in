/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:40:37 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:40:37 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 0;
	if (n < 0)
	{
		tmp *= -1;
		len = 1;
	}
	len += ft_intlen(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

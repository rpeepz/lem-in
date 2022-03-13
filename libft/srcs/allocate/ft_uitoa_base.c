/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:41:25 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:41:25 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	g_base[] = "0123456789ABCDEF";

char	*ft_uitoa_base(unsigned int n, int base)
{
	unsigned int	tmp;
	int				len;
	char			*str;

	tmp = n;
	len = 1;
	while (tmp / base)
	{
		tmp /= base;
		len++;
	}
	tmp = n;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = g_base[(tmp % base)];
		tmp /= base;
	}
	return (str);
}

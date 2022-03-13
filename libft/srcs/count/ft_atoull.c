/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:30:02 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:30:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *str)
{
	int					i;
	unsigned long long	n;

	n = 0;
	if (!str)
		return (n);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || \
			str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

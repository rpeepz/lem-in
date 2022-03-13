/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:55:17 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:55:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		if (s[i++] == (char)c)
			return (--i);
	return (-1);
}

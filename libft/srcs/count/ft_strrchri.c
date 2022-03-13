/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:55:44 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:55:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchri(const char *s, int c)
{
	size_t		i;
	int			z;

	i = 0;
	z = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == (char)c)
			z = i;
	return (z);
}

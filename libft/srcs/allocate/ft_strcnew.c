/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:15:40 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:15:40 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(size_t len, char c)
{
	char	*new;
	size_t	i;

	if (len)
	{
		new = (char *)malloc(sizeof(char) * len + 1);
		if (!new)
			return (NULL);
	}
	i = -1;
	while (++i < len)
		new[i] = c;
	new[i] = '\0';
	return (new);
}

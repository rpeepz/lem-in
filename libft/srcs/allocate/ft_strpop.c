/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by jmbomeyo          #+#    #+#             */
/*   Updated: 2022/03/13 18:37:14 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpop(char *str, size_t id)
{
	size_t	len;
	size_t	i;
	char	*popped;

	len = ft_strlen(str);
	if (id < len)
	{
		popped = (char *)malloc(len * sizeof(char));
		if (!popped)
			return (NULL);
		popped[len - 1] = '\0';
		i = -1;
		while (++i < id)
			popped[i] = str[i];
		while (++i < len)
			popped[i - 1] = str[i];
		return (popped);
	}
	return (NULL);
}

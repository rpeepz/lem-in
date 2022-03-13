/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:54:10 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:54:10 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = (int)ft_strlen(s1);
	while (s2[i] && i < (int)n)
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (s1);
}

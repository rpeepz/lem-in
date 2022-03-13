/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:57:23 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 11:57:23 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while ((s1[i] != '\0') && (s1[i] == s2[i]) && (i < (int)n))
		i++;
	if (i != (int)n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

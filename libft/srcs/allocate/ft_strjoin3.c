/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:04:49 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:04:49 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len[3];

	if (!s1 || !s2 || !s3)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	len[2] = ft_strlen(s3);
	new_str = ft_strnew(len[0] + len[1] + len[2]);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len[0])
		new_str[i] = s1[i];
	while (++j < len[1])
		new_str[i++] = s2[j];
	j = -1;
	while (++j < len[2])
		new_str[i++] = s3[j];
	new_str[i] = '\0';
	return (new_str);
}

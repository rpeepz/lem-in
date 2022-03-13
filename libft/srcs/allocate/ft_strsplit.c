/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:34:33 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/12 12:34:33 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		++i;
	while (s[i] && s[i] != c)
	{
		++i;
		++len;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		n;

	n = ft_countwords(s, c);
	arr = ft_memalloc(sizeof(char *) * (n + 1));
	i = 0;
	j = 0;
	while (i < n)
	{
		arr[i] = ft_strsub(s, j, word_len(&s[j], c));
		if (ft_strchri(arr[i], '\r') > 0)
			arr[i][ft_strchri(arr[i], '\r')] = '\0';
		j += ft_strlen(arr[i]) + 1;
		++i;
	}
	arr[i] = NULL;
	return (arr);
}

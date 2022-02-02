/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:24:11 by rpapagna          #+#    #+#             */
/*   Updated: 2022/01/17 12:24:11 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			reverse_array(char **array, int n)
{
	int		s;
	int		e;
	int		ret;
	char	*tmp;

	s = 0;
	e = 0;
	while (array[s] && s < n)
		++s;
	ret = s;
	while (--s > e)
	{
		tmp = array[s];
		array[s] = array[e];
		array[e] = tmp;
		++e;
	}
	return (ret);
}

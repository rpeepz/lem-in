/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:40:23 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:43:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

void	init_result(char *result, size_t k, int sign)
{
	size_t	i;

	i = 0;
	if (sign)
		result[i++] = '-';
	while (i < k)
		result[i++] = '0';
	result[i] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:18:20 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 14:23:50 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

void	carry(char *result, size_t k, int type)
{
	if (type && k && result[k] < '0')
	{
		result[k] += 10;
		result[k - 1] -= 1;
	}
	else if (!type && k && result[k] > '9')
	{
		result[k] -= 10;
		result[k - 1] += 1;
	}
}

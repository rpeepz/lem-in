/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:35:44 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/17 12:55:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Assumes zero as input minimum
*/

double	ft_map_zero(double in, double max, double start, double end)
{
	if (in >= max)
		return (end);
	if (in <= 0)
		return (start);
	return (in * ((end - start) / (max)) + start);
}

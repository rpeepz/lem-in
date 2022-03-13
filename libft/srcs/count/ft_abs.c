/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:35:44 by rpapagna          #+#    #+#             */
/*   Updated: 2022/03/13 17:47:50 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

double	abs_double(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

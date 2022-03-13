/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_remainder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:46:52 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/28 13:42:35 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbignum.h"

t_bignum	*init_remainder(char *dividend, size_t size)
{
	t_bignum	*bignum_remainder;
	char		*remainder;

	remainder = (char *)malloc(sizeof(char) * (size + 1));
	ft_bzero(remainder, size);
	size -= 1;
	ft_strncat(remainder, dividend, size);
	bignum_remainder = bignum_init(remainder);
	free(remainder);
	return (bignum_remainder);
}

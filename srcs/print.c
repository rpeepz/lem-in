/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:56:14 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/02 22:56:14 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		print_movement(int a, char *s)
{
	ft_putchar('L');
	ft_putnbr(a);
	ft_putchar('-');
	a = -1;
	while (s[++a])
		ft_putchar(s[a]);
	ft_putchar(' ');
}

void		print_file(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\r')
			ft_putchar(s[i]);
		++i;
	}
	ft_putchar('\n');
}

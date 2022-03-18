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

#include "lemin.h"

void	print_movement(int a, char *s)
{
	char	*nbr;
	char	*out;

	if (!s)
		return ;
	nbr = ft_itoa(a);
	out = ft_memalloc(ft_strlen(nbr) + ft_strlen(s) + 3);
	ft_strcat(out, "L");
	ft_strcat(out, nbr);
	ft_strcat(out, "-");
	ft_strcat(out, s);
	ft_putstr(out);
	ft_memdel((void **)&nbr);
	ft_memdel((void **)&out);
}

void	print_file(char *s)
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

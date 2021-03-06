/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:02:37 by rpapagna          #+#    #+#             */
/*   Updated: 2022/02/04 13:02:37 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	continue_movement(int **farm, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (farm[i][1] > 0)
			return (1);
		++i;
	}
	return (0);
}

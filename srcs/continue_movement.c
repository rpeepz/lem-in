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

#include "lem-in.h"

int		continue_movement(int **path_info, int n)
{
	int		i;
	
	i = 0;
	while (i < n)
	{
		if (path_info[i][1])
			return (1);
		++i;
	}
	return (0);
}

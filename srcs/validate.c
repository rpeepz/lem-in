/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:28:50 by rpapagna          #+#    #+#             */
/*   Updated: 2021/12/17 16:18:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	validate(t_lem_in *lem_in)
{
	if (!lem_in->ants || !lem_in->start_id || !lem_in->end_id || \
		!lem_in->adj_list || (lem_in->count_paths && !lem_in->path[0][0]))
		return (1);
	return (0);
}

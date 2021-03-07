/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takewhile_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "takeobj.h"

void	*takewhile_next(t_obj *it)
{
	t_state	*state;
	void	*item;

	state = it->state;
	item = next(state->inner);
	if (item && (*state->pred)(item))
		return (item);
	if (item == NULL)
		state->inner = NULL;
	return (NULL);
}

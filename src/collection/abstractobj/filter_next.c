/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filter_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_pred	p;
	void	*item;

	it = (void *)itobj;
	state = it->state;
	p = state->func;
	while ((item = next(state->inner)))
	{
		if ((*p)(item))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

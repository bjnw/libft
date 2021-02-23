/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filternot_next_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filternot_next_r(t_obj *itobj)
{
	t_itobj		*it;
	t_state		*state;
	t_pred_r	p;
	void		*item;

	it = (void *)itobj;
	state = it->state;
	p = state->func;
	while ((item = next(state->inner)))
	{
		if (!(*p)(state->ctx, item))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

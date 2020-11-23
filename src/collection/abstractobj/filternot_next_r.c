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
	t_pred_r	p;
	void		*item;

	it = (void *)itobj;
	p = it->state->func;
	while ((item = next(it->state->inner)))
	{
		if (!(*p)(it->state->ctx, item))
			return (item);
	}
	it->state->inner = NULL;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_next_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "filtermapobj.h"

void	*filter_next_r(t_obj *itobj)
{
	t_itobj		*it;
	t_pred_r	p;
	void		*item;

	it = (void *)itobj;
	p = it->state->callback;
	while ((item = next(it->nested)))
	{
		if ((*p)(it->state->ctx, item))
			return (item);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filternot_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filternot_next(t_obj *itobj)
{
	t_itobj	*it;
	t_pred	p;
	void	*item;

	it = (void *)itobj;
	p = it->state->func;
	while ((item = next(it->state->inner)))
	{
		if (!(*p)(item))
			return (item);
	}
	it->state->inner = NULL;
	return (NULL);
}

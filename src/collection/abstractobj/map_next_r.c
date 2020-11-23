/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_next_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"
#include "libft.h"

void	*map_next_r(t_obj *itobj)
{
	t_itobj	*it;
	t_f2s_r	f;
	void	*item;

	it = (void *)itobj;
	item = next(it->state->inner);
	if (!item)
	{
		it->state->inner = NULL;
		return (NULL);
	}
	f = it->state->func;
	ft_memcpy(it->state->data, item, itobj->meta->itemsize);
	(*f)(it->state->ctx, it->state->data);
	return (it->state->data);
}

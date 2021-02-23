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
	t_state	*state;
	t_f2_r	f;
	void	*item;

	it = (void *)itobj;
	state = it->state;
	if ((item = next(state->inner)))
	{
		f = state->func;
		ft_memcpy(state->data, item, itobj->meta->itemsize);
		return ((*f)(state->ctx, state->data));
	}
	state->inner = NULL;
	return (NULL);
}

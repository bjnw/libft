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

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "filtermapitobj.h"
#include "libft.h"

void	*map_next_r(t_obj *itobj)
{
	t_itobj	*cl;
	t_state	*state;
	t_f1s_r	f;
	void	*item;

	cl = (t_itobj *)itobj;
	state = cl->state;
	f = state->callback;
	if ((item = next(cl->nested)))
	{
		ft_memcpy(state->data, item, itobj->meta->itemsize);
		(*f)(state->ctx, state->data);
		return (state->data);
	}
	delete(itobj);
	return (NULL);
}

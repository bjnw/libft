/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermap_next.c                                   :+:      :+:    :+:   */
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

void	*filtermap_next(t_obj *itobj)
{
	t_itobj	*cl;
	t_state	*state;
	t_f1	f;
	void	*item;
	size_t	itemsize;

	cl = (t_itobj *)itobj;
	state = cl->state;
	f = state->callback;
	itemsize = itobj->meta->itemsize;
	while ((item = next(cl->nested)))
	{
		ft_memcpy(state->data, item, itemsize);
		if ((*f)(state->data))
			return (state->data);
	}
	delete(itobj);
	return (NULL);
}

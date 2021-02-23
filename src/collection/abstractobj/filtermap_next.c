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

#include "filtermapobj.h"
#include "libft.h"

void	*filtermap_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_f1	f;
	void	*item;
	size_t	itemsize;

	it = (void *)itobj;
	state = it->state;
	f = state->func;
	itemsize = itobj->meta->itemsize;
	while ((item = next(state->inner)))
	{
		ft_memcpy(state->data, item, itemsize);
		if ((item = (*f)(state->data)))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

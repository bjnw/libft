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
	t_f1	f;
	void	*item;
	size_t	itemsize;

	it = (void *)itobj;
	f = it->state->func;
	itemsize = itobj->meta->itemsize;
	while ((item = next(it->state->inner)))
	{
		ft_memcpy(it->state->data, item, itemsize);
		if ((*f)(it->state->data))
			return (it->state->data);
	}
	it->state->inner = NULL;
	return (NULL);
}

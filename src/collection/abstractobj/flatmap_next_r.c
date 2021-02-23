/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap_next_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flattenobj.h"
#include "libft.h"

void	*flatmap_next_r(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_f2_r	f;
	void	*item;
	void	**itp;

	it = (void *)itobj;
	state = it->state;
	while (true)
	{
		item = next(state->innerb);
		if (item)
		{
			f = state->func;
			ft_memcpy(state->data, item, itobj->meta->itemsize);
			return ((*f)(state->ctx, state->data));
		}
		itp = next(state->innera);
		if (!itp)
			break ;
		state->innerb = iter(*itp);
	}
	state->innera = NULL;
	state->innerb = NULL;
	return (NULL);
}

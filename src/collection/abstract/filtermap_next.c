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

void	*filtermap_next(t_obj *it)
{
	t_state	*state;
	t_f1	f;
	void	*item;
	size_t	itemsize;

	state = it->state;
	f = state->func;
	itemsize = it->meta->itemsize;
	while ((item = next(state->inner)))
	{
		ft_memcpy(state->item, item, itemsize);
		if ((item = (*f)(state->item)))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

void	*filtermap_next_r(t_obj *it)
{
	t_state	*state;
	t_f2_r	f;
	void	*item;
	size_t	itemsize;

	state = it->state;
	f = state->func;
	itemsize = it->meta->itemsize;
	while ((item = next(state->inner)))
	{
		ft_memcpy(state->item, item, itemsize);
		if ((item = (*f)(state->arg, state->item)))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

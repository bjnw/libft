/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"
#include "libft.h"

void	*map_next(t_obj *it)
{
	t_state	*state;
	t_f1	f;
	void	*item;

	state = it->state;
	if ((item = next(state->inner)))
	{
		f = state->func;
		ft_memcpy(state->item, item, it->meta->itemsize);
		return ((*f)(state->item));
	}
	state->inner = NULL;
	return (NULL);
}

void	*map_next_r(t_obj *it)
{
	t_state	*state;
	t_f2_r	f;
	void	*item;

	state = it->state;
	if ((item = next(state->inner)))
	{
		f = state->func;
		ft_memcpy(state->item, item, it->meta->itemsize);
		return ((*f)(state->arg, state->item));
	}
	state->inner = NULL;
	return (NULL);
}

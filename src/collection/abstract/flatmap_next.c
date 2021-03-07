/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flattenobj.h"
#include "libft.h"

void	*flatmap_next(t_obj *it)
{
	t_state	*state;
	t_f1	f;
	void	*item;
	void	**itp;

	state = it->state;
	while (true)
	{
		item = next(state->innerb);
		if (item)
		{
			f = state->func;
			ft_memcpy(state->item, item, it->meta->itemsize);
			return ((*f)(state->item));
		}
		itp = next(state->innera);
		if (itp == NULL)
			break ;
		state->innerb = iter(*itp);
	}
	state->innera = NULL;
	state->innerb = NULL;
	return (NULL);
}

void	*flatmap_next_r(t_obj *it)
{
	t_state	*state;
	t_f2_r	f;
	void	*item;
	void	**itp;

	state = it->state;
	while (true)
	{
		item = next(state->innerb);
		if (item)
		{
			f = state->func;
			ft_memcpy(state->item, item, it->meta->itemsize);
			return ((*f)(state->arg, state->item));
		}
		itp = next(state->innera);
		if (itp == NULL)
			break ;
		state->innerb = iter(*itp);
	}
	state->innera = NULL;
	state->innerb = NULL;
	return (NULL);
}

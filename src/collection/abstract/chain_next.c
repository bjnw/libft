/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainobj.h"

void	*chain_next(t_obj *it)
{
	t_state	*state;
	void	*item;

	state = it->state;
	while (state->innera)
	{
		item = next(state->innera);
		if (item)
			return (item);
		state->innera = state->innerb;
		state->innerb = NULL;
	}
	return (NULL);
}

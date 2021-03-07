/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unzip_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*unzip_next(t_obj *it)
{
	t_state	*state;
	t_pair	*pair;
	void	*item;

	state = it->state;
	while (true)
	{
		if ((item = state->pair.a))
			state->pair.a = NULL;
		else if ((item = state->pair.b))
			state->pair.b = NULL;
		if (item)
			return (item);
		pair = next(state->innera);
		if (pair == NULL)
			break ;
		state->pair = *pair;
	}
	state->innera = NULL;
	return (NULL);
}

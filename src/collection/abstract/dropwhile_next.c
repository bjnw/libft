/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropwhile_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dropobj.h"
#include "libft.h"

void	*dropwhile_next(t_obj *it)
{
	t_state	*state;
	void	*item;

	state = it->state;
	while ((item = next(state->inner)))
	{
		if ((*state->pred)(item))
			continue ;
		it->next = inner_next;
		return (item);
	}
	state->inner = NULL;
	return (NULL);
}

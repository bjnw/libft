/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropwhle_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dropobj.h"
#include "libft.h"

void	*dropwhile_next(t_obj *itobj)
{
	t_itobj	*it;
	void	*item;

	it = (void *)itobj;
	while ((item = next(it->state->inner)))
	{
		if (it->state->pred(item))
			continue ;
		it->iterable.next = inner_next;
		return (item);
	}
	it->state->inner = NULL;
	return (NULL);
}

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
#include "libft.h"

void	*chain_next(t_obj *itobj)
{
	t_itobj	*it;
	void	*item;

	it = (void *)itobj;
	if ((item = next(it->state->innera)))
		return (item);
	if (!it->state->innerb)
		return (NULL);
	it->state->innera = it->state->innerb;
	it->state->innerb = NULL;
	item = next(it->state->innera);
	return (item);
}

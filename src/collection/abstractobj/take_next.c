/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "takedropobj.h"

void	*take_next(t_obj *itobj)
{
	t_itobj *it;

	it = (void *)itobj;
	if (it->state->n--)
		return (next(it->nested));
	return (NULL);
}

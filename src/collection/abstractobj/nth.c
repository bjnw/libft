/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nth.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"

void	*nth(t_obj *itobj, ssize_t n)
{
	void *item;

	if (n < 0)
	{
		n += itobj->meta->size;
		if (n < 0)
			n = 0;
	}
	item = next(itobj);
	while (item && n--)
	{
		item = next(itobj);
	}
	return (item);
}

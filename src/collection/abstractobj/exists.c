/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

bool	exists(const t_obj *obj, t_pred p)
{
	void *it;
	void *item;

	it = iter(obj);
	while ((item = next(it)))
	{
		if ((*p)(item))
		{
			delete(it);
			return (true);
		}
	}
	return (false);
}

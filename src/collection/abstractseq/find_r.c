/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

void	*find_r(const t_obj *obj, const void *val, void *ctx,
			int (*cmp)(void *, const void *, const void *))
{
	void	*it;
	void	*item;

	it = iter(obj);
	while ((item = next(it)))
	{
		if ((*cmp)(ctx, item, val) == 0)
		{
			free(it);
			return (item);
		}
	}
	return (NULL);
}

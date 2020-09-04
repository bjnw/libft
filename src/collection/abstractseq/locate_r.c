/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

ssize_t	locate_r(const t_obj *obj, const void *val, void *ctx,
			int (*cmp)(void *, const void *, const void *))
{
	ssize_t	ret;
	void	*it;
	void	*item;

	ret = 0;
	it = iter(obj);
	while ((item = next(it)))
	{
		if ((*cmp)(ctx, item, val) == 0)
		{
			free(it);
			return (ret);
		}
		ret++;
	}
	return (-1);
}
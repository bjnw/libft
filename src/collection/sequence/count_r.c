/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/generic.h"

ssize_t	count_r(const t_obj *obj, const void *val, void *ctx,
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
			ret++;
	}
	return (ret);
}

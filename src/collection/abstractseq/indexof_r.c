/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

ssize_t	indexof_r(const t_obj *seq, const void *value, const void *ctx,
			int (*cmp)(const void *, const void *, const void *))
{
	ssize_t	index;
	void	*it;
	void	*item;

	index = 0;
	it = iter(seq);
	while ((item = next(it)))
	{
		if ((*cmp)(ctx, item, value) == 0)
		{
			free(it);
			return (index);
		}
		index++;
	}
	return (-1);
}

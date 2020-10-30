/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

void	*find(const t_obj *seq, const void *value,
			int (*cmp)(const void *, const void *))
{
	void *it;
	void *item;

	it = iter(seq);
	while ((item = next(it)))
	{
		if ((*cmp)(item, value))
			continue ;
		free(it);
		return (item);
	}
	return (seq->fallback);
}

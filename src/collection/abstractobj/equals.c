/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"

bool	equals(const t_obj *lhs, const t_obj *rhs,
			int (*cmp)(const void *, const void *))
{
	void *itl;
	void *itr;
	void *iteml;
	void *itemr;

	if (size(lhs) != size(rhs))
		return (false);
	itl = iter(lhs);
	itr = iter(rhs);
	while (true)
	{
		iteml = next(itl);
		itemr = next(itr);
		if (!iteml || !itemr || (*cmp)(iteml, itemr) != 0)
			break ;
	}
	if (!iteml && !itemr)
		return (true);
	if (iteml)
		free(itl);
	if (itemr)
		free(itr);
	return (false);
}

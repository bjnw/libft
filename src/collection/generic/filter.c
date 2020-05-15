/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/generic.h"

void	*filter(const t_obj *obj, bool (*p)(const void *))
{
	void	*ret;
	void	*it;
	void	*item;

	ret = copy(obj);
	it = iter(obj);
	while ((item = next(it)))
	{
		if ((*p)(item))
			add(ret, item);
	}
	return (ret);
}

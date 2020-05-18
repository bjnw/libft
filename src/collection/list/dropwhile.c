/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*dropwhile(t_obj *list, bool (*p)(const void *))
{
	t_iter	*ret;
	void	*it;
	void	*item;
	ssize_t	n;

	n = 0;
	it = iter(list);
	while ((item = next(it)))
	{
		if (!(*p)(item))
			return (stepby(it, n, 1, list->size - n));
		n++;
	}
	ret = stepby(list, 0, 0, 0);
	return (ret);
}

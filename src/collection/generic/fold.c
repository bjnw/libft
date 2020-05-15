/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/generic.h"

void	*fold(const t_obj *obj,
			void *(*op)(void *, void *), void *init)
{
	void	*ret;
	void	*it;
	void	*item;

	it = iter(obj);
	if (init)
		ret = init;
	else
		ret = next(it);
	while ((item = next(it)))
		ret = (*op)(ret, item);
	return (ret);
}

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

bool	equals(const t_obj *a, const t_obj *b, t_cmp cmp)
{
	void *ita;
	void *itb;
	void *itema;
	void *itemb;

	if (size(a) != size(b))
		return (false);
	ita = iter(a);
	itb = iter(b);
	while (true)
	{
		itema = next(ita);
		itemb = next(itb);
		if (!itema || !itemb || (*cmp)(itema, itemb) != 0)
			break ;
	}
	if (!itema && !itemb)
		return (true);
	if (itema)
		delete(ita);
	if (itemb)
		delete(itb);
	return (false);
}

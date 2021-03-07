/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	extend(t_obj *dst, const t_obj *src)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;
	t_putfn	tmp;

	it = iter(src);
	next = it->next;
	tmp = dst->put;
	dst->put = putbyref;
	while ((item = (*next)(it)))
		add(dst, item);
	dst->put = tmp;
	delete(it);
}

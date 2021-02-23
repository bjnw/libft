/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "libft.h"

void	patch(t_obj *dst, const t_obj *src, ssize_t from, ssize_t count)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	t_pair	*pair;
	size_t	itemsize;

	it = zip(drop(dst, from), take(src, count));
	next = it->next;
	itemsize = src->meta->itemsize;
	while ((pair = (*next)(it)))
		ft_memcpy(pair->a, pair->b, itemsize);
	delete(it);
}

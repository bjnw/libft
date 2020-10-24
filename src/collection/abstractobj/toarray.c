/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toarray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "libft.h"

void	*toarray(const t_obj *obj)
{
	void	*data;
	t_meta	*meta;
	void	*it;
	void	*item;
	void	*p;

	meta = obj->meta;
	data = xmalloc(meta->size * meta->itemsize);
	p = data;
	it = iter(obj);
	while ((item = next(it)))
		p = ft_mempcpy(p, item, meta->itemsize);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobuffer.c                                         :+:      :+:    :+:   */
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

void	tobuffer(void *buf, const t_obj *obj)
{
	void	*it;
	void	*item;
	size_t	itemsize;

	it = iter(obj);
	itemsize = obj->meta->itemsize;
	while ((item = next(it)))
		buf = ft_mempcpy(buf, item, itemsize);
}

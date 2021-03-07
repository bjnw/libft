/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobuf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"
#include "libft.h"

void	tobuf(void *buf, const t_obj *obj)
{
	t_obj	*it;
	void	*item;
	size_t	itemsize;

	it = iter(obj);
	itemsize = obj->meta->itemsize;
	while ((item = next(it)))
		buf = ft_mempcpy(buf, item, itemsize);
}

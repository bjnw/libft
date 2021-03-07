/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"
#include "libft.h"

// TODO iter_copy() should be recursive, scheisse

void	*copy(const t_obj *src)
{
	t_obj	*base;
	t_obj	*new;

	base = (void *)src->meta - offsetof(t_obj, tag);
	if (base->type == Iterator)
		return (base);
	new = memdup(base, OBJECT_SIZE + base->tagsize);
	new->meta = ft_memset(new->tag, 0, base->tagsize);
	new->meta->itemsize = base->meta->itemsize;
	return (new);
}

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

#include <stdlib.h>

#include "libft.h"
#include "vectorobj.h"

void	patch(t_obj *dst, const t_obj *src, ssize_t from)
{
	void *itdst;
	void *itsrc;
	void *itemdst;
	void *itemsrc;

	itdst = view(dst, from, size(src), 1);
	itsrc = iter(src);
	while (true)
	{
		itemdst = next(itdst);
		itemsrc = next(itsrc);
		if (!itemdst || !itemsrc)
			break ;
		ft_memcpy(itemdst, itemsrc, dst->itemsize);
	}
	if (itemdst)
		free(itdst);
	if (itemsrc)
		free(itsrc);
}

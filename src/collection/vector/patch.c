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

#include "libft.h"
#include "vectorobj.h"

void	patch(t_obj *dst, const t_obj *src, ssize_t from)
{
	void	*itdst;
	void	*itsrc;
	void	*itemdst;
	void	*itemsrc;
	ssize_t	n;

	n = dst->size;
	if (from < 0)
	{
		from += n;
		if (from < 0)
			from = 0;
	}
	else if (from > n)
		from = n;
	itdst = drop(dst, from);
	itsrc = iter(src);
	while (true)
	{
		itemdst = next(itdst);
		itemsrc = next(itsrc);
		if (!itemdst || !itemsrc)
			break ;
		ft_memcpy(itemdst, itemsrc, dst->itemsize);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*pop(t_obj *vect, long index, void *out)
{
	void	*item;
	long	n;

	n = vect->meta->size;
	if (index < 0)
		index += n;
	if (!item_exists(vect, index))
		return (NULL);
	item = vector_getitem(vect, index);
	if (out)
		ft_memcpy(out, item, vect->meta->itemsize);
	if (index + 1 < n)
		vector_lshitems(vect, index + 1);
	vector_resize(vect, n - 1);
	return (out);
}

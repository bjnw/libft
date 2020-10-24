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

void	*pop(t_obj *vector, ssize_t index, void *out)
{
	t_meta	*meta;
	void	*item;
	ssize_t	n;

	meta = vector->meta;
	n = meta->size;
	if (index < 0)
		index += n;
	if (!item_exists(vector, index))
		return (NULL);
	item = vector_getitem(vector, index);
	if (out)
		ft_memcpy(out, item, meta->itemsize);
	if (index + 1 < n)
		vector_lshitems(vector, index + 1);
	vector_resize(vector, n - 1);
	return (out);
}

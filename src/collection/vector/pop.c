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
	void	*item;
	ssize_t	n;

	n = vector->size;
	if (index < 0)
		index += n;
	if (!item_exists(vector, index))
		return (NULL);
	item = vector_getitem(vector, index);
	ft_memcpy(out, item, vector->itemsize);
	if (index + 1 < n)
		vector_lshitems(vector, index + 1);
	vector_resize(vector, n - 1);
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*vector_add(t_obj *vector, va_list ap)
{
	const void	*value;
	void		*item;
	ssize_t		n;

	n = vector->meta->size;
	vector_resize(vector, n + 1);
	value = va_arg(ap, const void *);
	item = vector_setitem(vector, n, value);
	return (item);
}

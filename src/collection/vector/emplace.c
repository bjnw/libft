/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*emplace(t_obj *vector, void *ctx,
			void (*f)(void *, void *))
{
	void	*item;
	ssize_t	n;

	n = vector->size;
	vector_resize(vector, n + 1);
	item = vector_getitem(vector, n);
	(*f)(ctx, item);
	return (item);
}

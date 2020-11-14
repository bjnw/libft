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

void	*emplace(t_obj *vector, void *arg, t_f2s f)
{
	void	*item;
	ssize_t	n;

	n = vector->meta->size;
	vector_resize(vector, n + 1);
	item = vector_getitem(vector, n);
	(*f)(item, arg);
	return (item);
}

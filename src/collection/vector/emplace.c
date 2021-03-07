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

/*
** TODO make it applicable for any collection
*/

void	*emplace(t_obj *vect, t_f2s_r f, const void *arg)
{
	void	*dst;
	long	n;

	n = vect->meta->size;
	vector_resize(vect, n + 1);
	dst = vector_getitem(vect, n);
	(*f)(arg, dst);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*vector_iter_impl(void)
{
	static const t_impl	impl = {
		.clone = generic_clone,
		.fold = vector_iter_fold,
		.fold_r = vector_iter_fold_r,
		.foreach = vector_iter_foreach,
		.foreach_r = vector_iter_foreach_r,
	};

	return ((void *)&impl);
}

void	*vector_iter(const t_obj *this)
{
	t_obj	*it;

	it = iterator(vector_next, this, STATE_SIZE);
	it->impl = vector_iter_impl();
	it->state->ptr = this->meta->data;
	it->state->n = this->meta->size;
	it->state->offset = this->meta->itemsize;
	return (it);
}

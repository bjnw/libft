/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	vector_foreach(t_obj *this, t_f1s f)
{
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	ptr = this->meta->data;
	n = this->meta->size;
	offset = this->meta->itemsize;
	while (n--)
	{
		(*f)(ptr);
		ptr += offset;
	}
}

void	vector_foreach_r(t_obj *this, t_f2s_r f, const void *arg)
{
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	ptr = this->meta->data;
	n = this->meta->size;
	offset = this->meta->itemsize;
	while (n--)
	{
		(*f)(arg, ptr);
		ptr += offset;
	}
}

void	vector_iter_foreach(t_obj *it, t_f1s f)
{
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	ptr = it->state->ptr;
	n = it->state->n;
	offset = it->state->offset;
	while (n--)
	{
		(*f)(ptr);
		ptr += offset;
	}
	delete(it);
}

void	vector_iter_foreach_r(t_obj *it, t_f2s_r f, const void *arg)
{
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	ptr = it->state->ptr;
	n = it->state->n;
	offset = it->state->offset;
	while (n--)
	{
		(*f)(arg, ptr);
		ptr += offset;
	}
	delete(it);
}

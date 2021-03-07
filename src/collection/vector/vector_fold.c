/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fold.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*vector_fold(const t_obj *this, void *init, t_f2 op)
{
	void		*acc;
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	acc = init;
	ptr = this->meta->data;
	n = this->meta->size;
	offset = this->meta->itemsize;
	if (acc == NULL && n != 0)
	{
		acc = ptr;
		ptr += offset;
		n--;
	}
	while (n--)
	{
		acc = (*op)(acc, ptr);
		ptr += offset;
	}
	return (acc);
}

void	*vector_fold_r(const t_obj *this, void *init,
			t_f3_r op, const void *arg)
{
	void		*acc;
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	acc = init;
	ptr = this->meta->data;
	n = this->meta->size;
	offset = this->meta->itemsize;
	if (acc == NULL && n != 0)
	{
		acc = ptr;
		ptr += offset;
		n--;
	}
	while (n--)
	{
		acc = (*op)(arg, acc, ptr);
		ptr += offset;
	}
	return (acc);
}

void	*vector_iter_fold(const t_obj *it, void *init, t_f2 op)
{
	void		*acc;
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	acc = init;
	ptr = it->state->ptr;
	n = it->state->n;
	offset = it->state->offset;
	if (acc == NULL && n != 0)
	{
		acc = ptr;
		ptr += offset;
		n--;
	}
	while (n--)
	{
		acc = (*op)(acc, ptr);
		ptr += offset;
	}
	delete((void *)it);
	return (acc);
}

void	*vector_iter_fold_r(const t_obj *it, void *init,
			t_f3_r op, const void *arg)
{
	void		*acc;
	void		*ptr;
	long		n;
	ptrdiff_t	offset;

	acc = init;
	ptr = it->state->ptr;
	n = it->state->n;
	offset = it->state->offset;
	if (acc == NULL && n != 0)
	{
		acc = ptr;
		ptr += offset;
		n--;
	}
	while (n--)
	{
		acc = (*op)(arg, acc, ptr);
		ptr += offset;
	}
	delete((void *)it);
	return (acc);
}

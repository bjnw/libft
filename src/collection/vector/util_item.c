/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*vector_getitem(const t_obj *this, long index)
{
	return (this->meta->data + index * this->meta->itemsize);
}

void	vector_copyitems(t_obj *dst, const t_obj *src)
{
	ft_memcpy(dst->meta->data, src->meta->data,
		src->meta->size * src->meta->itemsize);
}

void	vector_lshitems(t_obj *this, long index)
{
	void	*dst;
	void	*src;

	dst = vector_getitem(this, index);
	src = vector_getitem(this, index + 1);
	ft_memcpy(dst, src, (this->meta->size - index) * this->meta->itemsize);
}

void	vector_rshitems(t_obj *this, long index)
{
	void	*dst;
	void	*src;

	dst = vector_getitem(this, index + 1);
	src = vector_getitem(this, index);
	ft_memmove(dst, src, (this->meta->size - index) * this->meta->itemsize);
}

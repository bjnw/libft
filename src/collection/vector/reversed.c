/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*reversed(t_obj *vector)
{
	t_itobj *it;

	if (vector->meta->size == 0)
	{
		if (vector->iter)
			return (null_iter(vector));
		return (vector);
	}
	it = iter(vector);
	if (it->iterable.next == vector_next)
		it->iterable.next = vector_prev;
	else
		it->iterable.next = vector->next;
	ft_swap(&it->state->ptr, &it->state->end, sizeof(void *));
	return (it);
}

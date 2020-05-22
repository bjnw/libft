/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "slabobj.h"

void	sl_free(void *ptr)
{
	t_slab	*slab;
	size_t	n;

	slab = sl_root(ptr);
	n = (ptr - (void *)slab->items) / SLAB_ITEMSIZE;
	asm_bts(&slab->avail, n);
}

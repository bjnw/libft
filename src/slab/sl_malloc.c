/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "slabobj.h"

void	*sl_malloc(size_t size)
{
	void	*ret;
	t_slab	*slab;
	size_t	n;

	slab = sl_avail();
	n = asm_bsf(slab->avail);
	asm_btr(&slab->avail, n);
	ret = &slab->items[n];
	ft_memset(ret, 0, size);
	return (ret);
}

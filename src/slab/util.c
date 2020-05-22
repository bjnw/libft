/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "slabobj.h"

void	sl_new(void)
{
	t_slab	*slab;

	slab = xmalloc(SLAB_SIZE);
	slab->next = g_slab_cache;
	slab->avail = ~(~0ul << SLAB_ITEMS);
	g_slab_cache = slab;
}

void	*sl_avail(void)
{
	t_slab *slab;

	slab = g_slab_cache;
	while (slab)
	{
		if (slab->avail)
			return (slab);
		slab = slab->next;
	}
	sl_new();
	return (g_slab_cache);
}

void	*sl_root(const void *ptr)
{
	t_slab *slab;

	slab = g_slab_cache;
	while (ptr < (void *)slab ||
			ptr > (void *)slab + SLAB_SIZE)
		slab = slab->next;
	return (slab);
}

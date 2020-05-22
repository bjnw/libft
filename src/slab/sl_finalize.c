/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "slabobj.h"

void	sl_finalize(void)
{
	t_slab	*slab;
	void	*tmp;

	slab = g_slab_cache;
	while (slab)
	{
		tmp = slab;
		slab = slab->next;
		free(tmp);
	}
	g_slab_cache = NULL;
}

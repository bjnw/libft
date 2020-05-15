/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitset.h"

void	bs_set(void *data, size_t idx, int val)
{
	t_chunk *chunk;

	chunk = (t_chunk *)data + (idx >> CHUNK_EXP);
	if (val)
		*chunk |= 1 << (idx & CHUNK_MASK);
	else
		*chunk &= ~(1 << (idx & CHUNK_MASK));
}

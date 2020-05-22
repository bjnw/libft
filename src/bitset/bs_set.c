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

void	bs_set(void *data, size_t index, int val)
{
	t_chunk *chunk;

	chunk = (t_chunk *)data + (index >> CHUNK_EXP);
	if (val)
		asm_bts(chunk, index & CHUNK_MASK);
	else
		asm_btr(chunk, index & CHUNK_MASK);
}

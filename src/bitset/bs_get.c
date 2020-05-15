/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitset.h"

int		bs_get(void *data, size_t idx)
{
	t_chunk *chunk;

	chunk = (t_chunk *)data + (idx >> CHUNK_EXP);
	return (*chunk & (1 << (idx & CHUNK_MASK)));
}

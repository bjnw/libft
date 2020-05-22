/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSET_H
# define BITSET_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>

#include "asm.h"

typedef uint64_t	t_chunk;

# define CHUNK_EXP	6
# define CHUNK_MASK	(sizeof(t_chunk) * CHAR_BIT - 1)

void	*bs_new(size_t size);
void	bs_flip(void *data, size_t index);
void	bs_set(void *data, size_t index, int val);
int		bs_get(void *data, size_t index);
void	bs_delete(void *data);

#endif

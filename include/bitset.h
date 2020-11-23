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

typedef uintptr_t	t_chunk;

# define CHUNK_EXP	6
# define CHUNK_BITS	(sizeof(t_chunk) * CHAR_BIT)
# define CHUNK_MASK	(CHUNK_BITS - 1)

void	*bitset_new(size_t size);
int		bitset_get(const void *bitset, size_t n);
void	bitset_set(void *bitset, size_t n);
void	bitset_clear(void *bitset, size_t n);
void	bitset_toggle(void *bitset, size_t n);
void	bitset_free(void *bitset);

#endif

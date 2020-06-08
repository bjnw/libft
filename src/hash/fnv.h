/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNV_H
# define FNV_H

# include <stddef.h>
# include <stdint.h>

# define FNV1A32_PRIME			0x01000193u
# define FNV1A32_OFFSET_BASIS	0x811c9dc5u

# define FNV1A64_PRIME			0x100000001b3ul
# define FNV1A64_OFFSET_BASIS	0xcbf29ce484222325ul

uint32_t	fnv1a32(const void *s, size_t n);
uint32_t	fnv1a32s(const char *s);

uint64_t	fnv1a64(const void *s, size_t n);
uint64_t	fnv1a64s(const char *s);

#endif

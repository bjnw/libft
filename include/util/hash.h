/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stddef.h>
# include <stdint.h>

/*
** https://github.com/skeeto/hash-prospector
*/

uint32_t	lowbias32(uint32_t n);
uint32_t	triple32(uint32_t n);

uint32_t	fnv1a32(const void *s, size_t n);
uint32_t	fnv1a32s(const char *s);
uint64_t	fnv1a64(const void *s, size_t n);
uint64_t	fnv1a64s(const char *s);

#endif

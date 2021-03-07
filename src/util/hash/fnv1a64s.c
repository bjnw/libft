/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv1a64s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnv.h"

uint64_t	fnv1a64s(const char *s)
{
	uint64_t	ret;

	ret = FNV1A64_OFFSET_BASIS;
	while (*s)
	{
		ret ^= (uint8_t)(*s++);
		ret *= FNV1A64_PRIME;
	}
	return (ret);
}

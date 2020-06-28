/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv1a64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnv.h"

uint64_t	fnv1a64(const void *s, size_t n)
{
	const uint8_t	*data = s;
	const uint8_t	*end = data + n;
	uint64_t		ret;

	ret = FNV1A64_OFFSET_BASIS;
	while (data < end)
	{
		ret ^= *data++;
		ret *= FNV1A64_PRIME;
	}
	return (ret);
}

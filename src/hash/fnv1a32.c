/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv1a32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnv.h"

uint32_t	fnv1a32(const void *s, size_t n)
{
	const uint8_t	*data = s;
	const uint8_t	*end = data + n;
	uint32_t		ret;

	ret = FNV1A32_OFFSET_BASIS;
	while (data < end)
	{
		ret ^= *data++;
		ret *= FNV1A32_PRIME;
	}
	return (ret);
}

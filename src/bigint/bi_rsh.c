/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_rsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "bigint.h"
#include "libft.h"

void	bi_rsh(t_bigint *bi, uintmax_t i)
{
	t_comp *dst;
	t_comp *src;
	size_t size;

	if (i >= bi->size)
		bi_set(bi, 0);
	else
	{
		dst = bi->comps;
		src = bi->comps + i;
		size = bi->size - i;
		while (size--)
			*dst++ = *src++;
		bi->size -= i;
		ft_memset(dst, 0, sizeof(t_comp) * i);
	}
}

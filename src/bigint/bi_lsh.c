/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "bigintdecl.h"
#include "libft.h"

// TODO realloc
// TODO overflow

void	bi_lsh(t_bigint *bi, uintmax_t i)
{
	t_comp	*dst;
	t_comp	*src;
	size_t	size;

	if (i >= BI_COMPS)
		return (bi_set(bi, 0));
	size = bi->size - 1;
	dst = bi->comps + size + i;
	src = bi->comps + size;
	while (size--)
		*dst-- = *src--;
	bi->size += i;
	ft_memset(bi->comps, 0, sizeof(t_comp) * i);
}

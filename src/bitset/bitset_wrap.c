/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitsetdecl.h"
#include "libft.h"

t_bitset	*bitset_wrap(void *data, size_t nbits)
{
	t_bitset	*bset;

	bset = xmalloc(sizeof(*bset));
	bset->array = data;
	bset->nbits = nbits;
	bset->size = (nbits >> BASE_LOG2) + 1;
	return (bset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitsetdecl.h"
#include "libft.h"

void	bitset_resize(t_bitset *bset, size_t newbits)
{
	size_t	oldsize;
	size_t	newsize;

	oldsize = ((bset->nbits >> BASE_LOG2) + 1) * CHAR_BIT;
	newsize = ((newbits >> BASE_LOG2) + 1) * CHAR_BIT;
	bset->array = xrealloc(bset->array, newsize, oldsize);
	bset->nbits = newbits;
	bset->size = (newbits >> BASE_LOG2) + 1;
}

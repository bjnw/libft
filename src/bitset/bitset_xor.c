/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitsetdecl.h"

void	bitset_xor(t_bitset *lhs, const t_bitset *rhs)
{
	t_base	*a;
	t_base	*b;
	size_t	n;

	a = lhs->array;
	b = rhs->array;
	n = lhs->size;
	while (n--)
		*a++ ^= *b++;
}

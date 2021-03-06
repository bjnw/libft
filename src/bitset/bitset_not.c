/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitsetdecl.h"

void	bitset_not(t_bitset *bset)
{
	t_base	*a;
	size_t	n;

	a = bset->array;
	n = bset->size;
	while (n--)
	{
		*a = ~(*a);
		a++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifodecl.h"
#include "libft.h"

t_fifo	*fifo_new(size_t itemsize)
{
	t_fifo *fifo;

	fifo = xcalloc(1, sizeof(*fifo));
	fifo->itemsize = itemsize;
	return (fifo);
}

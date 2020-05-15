/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mw_pack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:23:00 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:26:00 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	mw_pack(int c)
{
	size_t bytes;

	if ((bytes = (unsigned char)c))
	{
		bytes |= bytes << 8;
		bytes |= bytes << 16;
		bytes |= bytes << 32;
	}
	return (bytes);
}

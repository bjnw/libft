/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:08:35 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 13:10:16 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	*ft_map(const void *data, size_t len, size_t size,
			void (*f)(void *))
{
	void *dst;

	dst = xmalloc(len * size);
	ft_memcpy(dst, data, len * size);
	ft_foreach(dst, len, size, f);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:02:25 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/25 18:59:19 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dst == src)
		return (dst);
	if (src > dst || dst > src + n)
		return (ft_memcpy(dst, src, n));
	pd = dst + n;
	ps = src + n;
	while (n--)
		*--pd = *--ps;
	return (dst);
}

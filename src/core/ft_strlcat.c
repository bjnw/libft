/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 03:17:05 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/17 23:52:25 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dst, size);
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_memcpy(dst + dlen, src, slen + 1);
	else if (size != 0)
	{
		ft_memcpy(dst + dlen, src, size - dlen - 1);
		dst[size - 1] = '\0';
	}
	return (dlen + slen);
}

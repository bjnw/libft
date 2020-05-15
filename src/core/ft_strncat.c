/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 03:08:38 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:00:18 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t dlen;
	size_t slen;

	dlen = ft_strlen(dst);
	slen = ft_strnlen(src, n);
	ft_memcpy(dst + dlen, src, slen);
	dst[dlen + slen] = '\0';
	return (dst);
}

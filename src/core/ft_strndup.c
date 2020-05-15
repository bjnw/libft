/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 04:32:56 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 10:49:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dst;
	size_t	len;

	len = ft_strnlen(s, n);
	dst = xmalloc(len + 1);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}

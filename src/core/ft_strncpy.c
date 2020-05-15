/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 04:38:58 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:00:14 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strnlen(src, n);
	if (len < n)
	{
		ft_memcpy(dst, src, len);
		ft_memset(dst + len, 0, n - len);
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

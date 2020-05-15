/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:23:54 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/21 22:23:54 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strnlen(src, n);
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (dst + len);
}

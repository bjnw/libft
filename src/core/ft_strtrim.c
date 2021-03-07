/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 08:00:44 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:53:18 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	const char	*p;
	char		*dst;
	size_t		len;

	if (*s == '\0')
		return ((char *)s);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (xcalloc(1, 1));
	p = s + ft_strlen(s) - 1;
	while (*p == ' ' || *p == '\t' || *p == '\n')
		p--;
	len = p - s + 1;
	dst = xmalloc(len + 1);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}

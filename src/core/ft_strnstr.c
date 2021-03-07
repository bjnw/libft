/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 06:25:52 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 08:03:34 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (n >= len && *haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}

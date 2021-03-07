/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:25:21 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/03 02:25:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strfind(const char *s, const char *sym, char **endptr)
{
	size_t	n;

	n = ft_strlen(sym) + 1;
	while (!ft_memchr(sym, *s, n))
		s++;
	if (endptr)
		*endptr = (char *)s;
	return ((char *)s);
}

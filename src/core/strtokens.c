/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:10:16 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 18:54:36 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

size_t	strtokens(const char *s, const char *delim)
{
	size_t	n;
	char	*p;

	if (*s == '\0')
		return (0);
	if (*delim == '\0')
		return (1);
	n = 0;
	p = (char *)s;
	while (strtoken(p, delim, &p))
		n++;
	return (n);
}

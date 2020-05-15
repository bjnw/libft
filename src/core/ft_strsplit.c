/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:39:53 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 18:59:56 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char	**ft_strsplit(const char *s, int delim)
{
	char	**pv;
	char	**p;
	char	*s0;
	size_t	n;

	if ((n = ft_strelems(s, delim)) == 0)
		return (NULL);
	pv = xmalloc((n + 1) * sizeof(char *));
	p = pv;
	while (n--)
	{
		s0 = ft_strjmp(&s, delim);
		*p++ = ft_strndup(s0, s - s0);
	}
	*p = NULL;
	return (pv);
}

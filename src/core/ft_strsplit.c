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
	const char	d[] = {delim, '\0'};
	char		**strv;
	char		**strp;
	char		*p;
	size_t		n;

	n = strtokens(s, d);
	if (n == 0)
		return (NULL);
	strv = xmalloc((n + 1) * sizeof(char *));
	strp = strv;
	while (n--)
	{
		p = strtoken(s, d, (char **)&s);
		*strp++ = ft_strndup(p, s - p);
	}
	*strp = NULL;
	return (strv);
}

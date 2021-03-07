/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:30:44 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/24 20:30:44 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strtoken(const char *s, const char *delim, char **endptr)
{
	char	*p;

	p = strskip(s, delim, NULL);
	if (*p == '\0')
	{
		if (endptr)
			*endptr = p;
		return (NULL);
	}
	strfind(p, delim, endptr);
	return (p);
}

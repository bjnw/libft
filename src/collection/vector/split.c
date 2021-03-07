/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*split(const char *s, const char *delim, size_t itemsize,
			void (*f)(void *, const char *, const char *))
{
	t_obj	*new;
	void	*it;
	void	*item;
	long	n;
	char	*p;

	n = strtokens(s, delim);
	new = vector(itemsize);
	vector_resize(new, n);
	it = vector_iter(new);
	while ((item = next(it)))
	{
		p = strtoken(s, delim, (char **)&s);
		(*f)(item, p, s);
	}
	return (new);
}

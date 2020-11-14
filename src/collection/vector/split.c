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

void	*split(const char *s, int delim, size_t itemsize,
			void (*parse)(void *, const char *, const char *))
{
	t_obj	*new;
	void	*it;
	void	*item;
	ssize_t	n;
	char	*s0;

	n = ft_strelems(s, delim);
	new = vector(itemsize);
	vector_resize(new, n);
	it = iter(new);
	while ((item = next(it)))
	{
		s0 = ft_strjmp(&s, delim);
		(*parse)(item, s0, s);
	}
	return (new);
}

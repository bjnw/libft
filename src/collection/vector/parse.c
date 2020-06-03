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

void	parse(t_obj *dst, const char *s, int delim,
			void (*f)(void *, const char *, const char *))
{
	void	*item;
	ssize_t	size;
	ssize_t	n;
	char	*s0;

	n = ft_strelems(s, delim);
	size = dst->size;
	vector_resize(dst, size + n);
	while (n--)
	{
		item = vector_getitem(dst, size);
		s0 = ft_strjmp(&s, delim);
		(*f)(item, s0, s);
		size++;
	}
}

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
			void (*f)(void *, const char *, const char *))
{
	t_obj	*ret;
	void	*item;
	ssize_t	n;
	char	*s0;

	n = ft_strelems(s, delim);
	ret = vector(n, itemsize);
	while (n--)
	{
		item = vector_getitem(ret, ret->size);
		s0 = ft_strjmp(&s, delim);
		(*f)(item, s0, s);
		ret->size++;
	}
	return (ret);
}

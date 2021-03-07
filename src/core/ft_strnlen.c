/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:49:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:00:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t n)
{
	void	*eol;

	eol = ft_memchr(s, '\0', n);
	if (eol == NULL)
		return (n);
	return ((uintptr_t)eol - (uintptr_t)s);
}

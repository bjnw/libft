/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strelems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:10:16 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 18:54:36 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "libft.h"

size_t	ft_strelems(const char *s, int delim)
{
	size_t elems;

	if (*s == '\0')
		return (0);
	if (delim == '\0')
		return (1);
	elems = 0;
	while (*ft_strjmp(&s, delim))
		elems++;
	return (elems);
}

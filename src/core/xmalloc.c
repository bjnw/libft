/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:20:21 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/25 23:20:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft.h"

void	*xmalloc(size_t size)
{
	void *data;

	if (size == 0)
		panic("malloc: invalid argument");
	data = malloc(size);
	if (data == NULL)
		panic("malloc: cannot allocate memory");
	return (data);
}

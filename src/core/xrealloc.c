/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:46:04 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 07:54:04 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*xrealloc(void *data, size_t newsize, size_t oldsize)
{
	void *newdata;

	if (newsize == 0)
	{
		free(data);
		return (NULL);
	}
	if (data == NULL)
		return (xmalloc(newsize));
	if (newsize == oldsize)
		return (data);
	newdata = xmalloc(newsize);
	ft_memcpy(newdata, data, ft_umin(newsize, oldsize));
	free(data);
	return (newdata);
}

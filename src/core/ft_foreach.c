/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:04:38 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/21 19:04:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	ft_foreach(void *data, size_t len, size_t size, void (*f)(void *))
{
	while (len--)
	{
		(*f)(data);
		data += size;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:42:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/25 11:09:50 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

uintmax_t	ft_atou(const char *s)
{
	uintmax_t n;

	n = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	while (ft_isdigit(*s))
		n = (n << 3) + (n << 1) + (*s++ & ~060);
	return (n);
}

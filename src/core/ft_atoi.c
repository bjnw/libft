/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:42:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/25 11:09:50 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>

#include "libft.h"

intmax_t	ft_atoi(const char *s)
{
	intmax_t	n;
	bool		negative;

	n = 0;
	while (ft_isspace(*s))
		s++;
	negative = (*s == '+') ^ (*s == '-') && *s++ == '-';
	while (ft_isdigit(*s))
		n = (n << 3) + (n << 1) + (*s++ & ~060);
	return (negative ? -n : n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:33:12 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/16 09:02:35 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>

#include "libft.h"

char	*ft_itoa(char *s, intmax_t n)
{
	char		*p;
	uintmax_t	n0;
	bool		negative;

	p = s;
	if (n == 0)
	{
		*p++ = '0';
		*p = '\0';
		return (s);
	}
	negative = n < 0;
	n0 = negative ? ft_abs(n) : (uintmax_t)n;
	while (n0)
	{
		*p++ = n0 % 10 + '0';
		n0 /= 10;
	}
	if (negative)
		*p++ = '-';
	*p = '\0';
	return (ft_strrev(s));
}

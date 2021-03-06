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

#include "libft.h"

char	*ft_itoa(char *s, int n)
{
	char	*p;
	bool	neg;

	p = s;
	neg = n < 0;
	while (n != 0)
	{
		*p++ = iabs(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		*p++ = '-';
	*p = '\0';
	return (strrev(s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:42:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/25 11:09:50 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"

/*
** TODO handle exp
*/

double	ft_atof(const char *s)
{
	double	val;
	double	frac;
	bool	neg;

	while (ft_isspace(*s))
		s++;
	neg = *s == '+' ^ *s == '-' && *s++ == '-';
	val = 0.0;
	while (ft_isdigit(*s))
		val = val * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		frac = 0.1;
		while (ft_isdigit(*++s))
		{
			val += (*s - '0') * frac;
			frac *= 0.1;
		}
	}
	return (neg ? -val : val);
}

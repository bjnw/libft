/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:25:21 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/03 02:25:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrev(char *s)
{
	char	*ret;
	char	*p;
	char	c;

	ret = s;
	p = s + ft_strlen(s) - 1;
	while (s < p)
	{
		c = *s;
		*s++ = *p;
		*p-- = c;
	}
	return (ret);
}
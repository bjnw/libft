/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 01:11:30 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/06 18:12:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	while (ft_tolower(*s1) == ft_tolower(*s2))
	{
		if (*s1++ == '\0')
			return (0);
		s2++;
	}
	return (ft_tolower(*s1) - ft_tolower(*s2));
}

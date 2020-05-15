/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:25:21 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/03 02:25:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char *eol;
	char *ret;

	ret = s;
	eol = s + ft_strlen(s);
	while (s < --eol)
		ft_memswap(s++, eol, sizeof(char));
	return (ret);
}

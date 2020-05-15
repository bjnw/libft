/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:30:44 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/24 20:30:44 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjmp(const char **s, int delim)
{
	const char	*s0;
	const char	*p;

	p = *s;
	while (*p == (unsigned char)delim)
		p++;
	s0 = p;
	while (*p && *p != (unsigned char)delim)
		p++;
	*s = p;
	return ((char *)s0);
}

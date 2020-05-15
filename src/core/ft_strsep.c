/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:30:44 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/24 20:30:44 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strsep(char **sp, int delim)
{
	char	*ret;
	char	*s;

	if ((s = *sp) == NULL)
		return (NULL);
	while (*s == delim)
		s++;
	if (*s == '\0')
	{
		*sp = NULL;
		return (NULL);
	}
	ret = s;
	while (*s && *s != delim)
		s++;
	if (*s)
		*s++ = '\0';
	else
		s = NULL;
	*sp = s;
	return (ret);
}

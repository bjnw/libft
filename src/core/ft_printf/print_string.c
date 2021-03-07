/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:19:05 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:21:56 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

void	print_string(char **buf, char fmt, t_flags *flags, va_list ap)
{
	const char	*s;

	(void)fmt;
	s = va_arg(ap, const char *);
	if (s == NULL)
		s = "(null)";
	buf_copy(buf, s, ft_strlen(s), flags);
}

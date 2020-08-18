/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:23 by diona             #+#    #+#             */
/*   Updated: 2020/02/20 19:22:36 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "util.h"

/*
** TODO g_bufcpy with overflow/flush
*/

int		ft_printf(const char *fmt, ...)
{
	char	buf[BUFF_SIZE];
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vsprintf(buf, fmt, ap);
	va_end(ap);
	write(STDOUT_FILENO, buf, ret);
	return (ret);
}

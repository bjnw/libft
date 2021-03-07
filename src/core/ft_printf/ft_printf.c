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

// TODO bufcpy with overflow/flush

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vprintf(fmt, ap);
	va_end(ap);
	return (ret);
}

int	ft_vprintf(const char *fmt, va_list ap)
{
	char	buf[BUFF_SIZE];
	int		ret;

	ret = ft_vsprintf(buf, fmt, ap);
	write(STDOUT_FILENO, buf, ret);
	return (ret);
}

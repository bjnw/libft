/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:19:05 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:21:56 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	print_char(char **buf, char fmt, t_flag *flags, va_list ap)
{
	char c;

	(void)fmt;
	c = va_arg(ap, int);
	if (flags->precision == 0)
		flags->precision++;
	buf_copy(buf, &c, sizeof(char), flags);
}

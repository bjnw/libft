/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:24:44 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:21:27 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

void	print_pointer(char **buf, char fmt, t_flags *flags, va_list ap)
{
	const void	*ptr;

	(void)fmt;
	ptr = va_arg(ap, const void *);
	if (ptr == NULL && flags->precision == 0)
	{
		flags->precision = 2;
		buf_copy(buf, "0x", 2, flags);
		return ;
	}
	flags->alter = ON;
	flags->uppercase = OFF;
	number(buf, (uintptr_t)ptr, 16, flags);
}

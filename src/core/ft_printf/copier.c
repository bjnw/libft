/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:50:29 by diona             #+#    #+#             */
/*   Updated: 2020/03/03 17:11:48 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	buf_copy(char **buf, const char *s, int len, t_flag *flags)
{
	char	pad;

	pad = flags->zero ? '0' : ' ';
	if (flags->precision != UNDEF)
		len = len < flags->precision ? len : flags->precision;
	if (!flags->left)
		while (flags->width-- > len)
			*((*buf)++) = pad;
	flags->width -= len;
	while (len--)
		*((*buf)++) = *s++;
	while (flags->width-- > 0)
		*((*buf)++) = pad;
}

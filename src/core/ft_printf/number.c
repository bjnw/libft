/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:30:40 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:35:19 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

static void	get_itoa_base(char *buf, uintmax_t num, int base, t_flags *flags)
{
	const char	*digits = "0123456789abcdef";
	char		*p;

	p = buf;
	if (num == 0)
		*p++ = '0';
	while (num > 0)
	{
		*p++ = digits[num % base];
		num /= base;
	}
	*p = '\0';
	if (flags->uppercase)
		ft_strupr(buf);
	strrev(buf);
}

int	get_prefix(char *prefix, t_flags *flags, int base)
{
	char	*p;

	p = prefix;
	if (flags->sign)
	{
		if (flags->negative)
			*prefix++ = '-';
		else if (flags->plus)
			*prefix++ = '+';
		else if (flags->space)
			*prefix++ = ' ';
	}
	else if (flags->alter && base != 10)
	{
		*prefix++ = '0';
		if (base == 2)
			*prefix++ = 'b';
		if (base == 16)
			*prefix++ = "xX"[flags->uppercase];
	}
	*prefix = '\0';
	return (prefix - p);
}

void	memset_leap(char **buf, int pad, int width)
{
	if (width > 0)
	{
		ft_memset(*buf, pad, width);
		*buf += width;
	}
}

void	number(char **buf, uintmax_t num, int base, t_flags *flags)
{
	char	tmp[65];
	char	prefix[3];
	int		tlen;
	int		plen;

	get_itoa_base(tmp, num, base, flags);
	plen = get_prefix(prefix, flags, base);
	tlen = ft_strlen(tmp);
	if (base == 8 && flags->precision > tlen)
		flags->width += plen;
	flags->precision = imax(tlen, flags->precision);
	flags->width -= plen + flags->precision;
	if (!flags->left && !flags->zero)
		memset_leap(buf, ' ', flags->width);
	*buf = ft_mempcpy(*buf, prefix, plen);
	if (!flags->left && flags->zero)
		memset_leap(buf, '0', flags->width);
	else if (base == 8)
		memset_leap(buf, '0', flags->precision - tlen - plen);
	else
		memset_leap(buf, '0', flags->precision - tlen);
	*buf = ft_mempcpy(*buf, tmp, tlen);
	if (flags->left)
		memset_leap(buf, ' ', flags->width);
}

void	zero(char **buf, int base, t_flags *flags)
{
	char	prefix[3];
	int		plen;

	if (base != 8 || flags->precision)
		flags->alter = OFF;
	if (flags->precision != 0)
		return (number(buf, 0, base, flags));
	plen = get_prefix(prefix, flags, base);
	flags->precision += plen;
	buf_copy(buf, prefix, plen, flags);
}

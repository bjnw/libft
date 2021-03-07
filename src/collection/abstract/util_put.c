/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"
#include "libft.h"

void	putbyte(void *dst, va_list ap, const t_meta *dummy)
{
	const unsigned char	item = va_arg(ap, unsigned int);

	(void)dummy;
	*(unsigned char *)dst = item;
}

void	putword(void *dst, va_list ap, const t_meta *dummy)
{
	const unsigned short	item = va_arg(ap, unsigned int);

	(void)dummy;
	*(unsigned short *)dst = item;
}

void	putdword(void *dst, va_list ap, const t_meta *dummy)
{
	const unsigned int	item = va_arg(ap, unsigned int);

	(void)dummy;
	*(unsigned int *)dst = item;
}

void	putqword(void *dst, va_list ap, const t_meta *dummy)
{
	const unsigned long	item = va_arg(ap, unsigned long);

	(void)dummy;
	*(unsigned long *)dst = item;
}

void	putbyref(void *dst, va_list ap, const t_meta *meta)
{
	const void	*src = va_arg(ap, const void *);

	ft_memcpy(dst, src, meta->itemsize);
}

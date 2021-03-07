/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_float_bufspec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:48 by diona             #+#    #+#             */
/*   Updated: 2020/03/19 20:59:30 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "util.h"

void	buf_prefix(char **buf, t_flags *orig, int len)
{
	char	prefix[2];
	t_flags	flags;

	if (!get_prefix(prefix, orig, 10))
		return ;
	flags = *orig;
	if (orig->zero || orig->left)
	{
		flags.width = 1;
		orig->width -= 1;
	}
	else
	{
		flags.width -= len;
		orig->width -= flags.width;
	}
	buf_copy(buf, prefix, ft_strlen(prefix), &flags);
}

void	buf_special(char **buf, char *s, t_flags *flags)
{
	flags->precision = UNDEF;
	flags->zero = OFF;
	buf_prefix(buf, flags, 3);
	buf_copy(buf, s, ft_strlen(s), flags);
}

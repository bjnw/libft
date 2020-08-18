/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:23 by diona             #+#    #+#             */
/*   Updated: 2020/03/11 14:41:39 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

/*
** % [parameter] [flags] [width] [.precision] [length] type
*/

int		get_atoi(const char **fmt)
{
	int		num;

	num = 0;
	while (ft_isdigit(**fmt))
		num = num * 10 + *((*fmt)++) - '0';
	return (num);
}

void	get_width(const char **fmt, t_flag *flags, va_list ap)
{
	if (**fmt == '*')
	{
		flags->width = va_arg(ap, int);
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
		flags->width = get_atoi(fmt);
}

void	get_precision(const char **fmt, t_flag *flags, va_list ap)
{
	while (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			flags->precision = va_arg(ap, int);
			(*fmt)++;
		}
		else
			flags->precision = get_atoi(fmt);
	}
}

void	get_modifier(const char **fmt, t_flag *flags)
{
	t_length modifier;

	modifier = none;
	if (**fmt == 'h')
		modifier = h;
	else if (**fmt == 'l')
		modifier = l;
	else if (**fmt == 'L')
		modifier = L;
	else if (**fmt == 'j')
		modifier = j;
	else if (**fmt == 'z')
		modifier = z;
	if (modifier == none)
		return ;
	(*fmt)++;
	if (modifier == h && **fmt == 'h')
		modifier = hh;
	else if (modifier == l && **fmt == 'l')
		modifier = ll;
	if (modifier == hh || modifier == ll)
		(*fmt)++;
	if (flags->modifier < modifier)
		flags->modifier = modifier;
}

void	get_flags(const char **fmt, t_flag *flags)
{
	while (true)
	{
		if (**fmt == '-')
			flags->left = ON;
		else if (**fmt == '+')
			flags->plus = ON;
		else if (**fmt == ' ')
			flags->space = ON;
		else if (**fmt == '0')
			flags->zero = ON;
		else if (**fmt == '#')
			flags->alter = ON;
		else
			break ;
		(*fmt)++;
	}
}

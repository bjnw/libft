/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:48 by diona             #+#    #+#             */
/*   Updated: 2020/03/19 20:59:30 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

t_bigint	*calc_intpart(int64_t power, uint64_t mantissa)
{
	t_bigint	*intpart;

	intpart = bi_new();
	bi_set(intpart, 2);
	bi_ipow(intpart, power);
	bi_imul(intpart, mantissa);
	return (intpart);
}

// TODO exp limits?

t_bigint	*calc_fracpart(int64_t power, uint64_t mantissa)
{
	t_bigint	*fracpart;
	t_bigint	multiplier;
	t_bigint	divider;

	fracpart = bi_new();
	bi_set(&multiplier, mantissa);
	if (power)
		bi_imul(&multiplier, 2);
	bi_set(&divider, 5);
	bi_ipow(&divider, LDBL_MANTISSA_BIT + power);
	bi_mul(&multiplier, &divider, fracpart);
	return (fracpart);
}

void	calc_guts(const t_dbl *dbl, t_guts *guts)
{
	uint64_t	power;
	int64_t		exponent;
	uint64_t	mantissa;

	power = 0;
	if ((exponent = dbl->bits.exponent - LDBL_BIAS) <= 0)
		power = -exponent + 1;
	else if (exponent > LDBL_MANTISSA_BIT)
		power = exponent - LDBL_MANTISSA_BIT;
	if (exponent > 0)
	{
		mantissa = dbl->bits.mantissa;
		if (exponent <= LDBL_MANTISSA_BIT)
			mantissa >>= LDBL_MANTISSA_BIT - exponent;
		guts->intpart = calc_intpart(power, mantissa);
	}
	if (exponent < LDBL_MANTISSA_BIT)
	{
		mantissa = dbl->bits.mantissa;
		if (exponent > 0)
			mantissa <<= exponent;
		guts->fracpart = calc_fracpart(power, mantissa);
		guts->fracsize = LDBL_MANTISSA_BIT + power;
	}
}

void	buf_bigint(char **buf, t_bigint *bi)
{
	t_comp	*comp;
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	flags.width = UNDEF;
	flags.precision = UNDEF;
	comp = bi->comps + bi->size - 1;
	number(buf, *comp, 10, &flags);
	flags.precision = 9;
	while (--comp >= bi->comps)
		number(buf, *comp, 10, &flags);
}

void	buf_guts(char **buf, t_guts *guts, t_flags *flags)
{
	int	blen;

	if (guts->intpart)
		buf_bigint(buf, guts->intpart);
	else
		*buf = ft_mempset(*buf, '0', 1);
	if (flags->precision || flags->alter)
		*buf = ft_mempset(*buf, '.', 1);
	if (guts->fracsize)
	{
		blen = get_blen(guts->fracpart);
		if (blen < guts->fracsize)
			*buf = ft_mempset(*buf, '0', guts->fracsize - blen);
		buf_bigint(buf, guts->fracpart);
	}
	if (flags->precision > guts->fracsize)
		*buf = ft_mempset(*buf, '0', flags->precision - guts->fracsize);
	else
		*buf -= guts->fracsize - flags->precision;
}

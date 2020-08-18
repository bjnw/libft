/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:47 by diona             #+#    #+#             */
/*   Updated: 2020/03/11 14:46:03 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdarg.h>
# include <stdint.h>

# include "bigint.h"

# define BUFF_SIZE 16069
# define ON		1
# define OFF	0
# define UNDEF	-1

# define VALID_FLAGS	"-+ 0123456789#*.lLhjz"

# define LDBL_BIAS			16382
# define LDBL_MANTISSA_BIT	64

typedef struct {
	uint64_t	mantissa: 64;
	uint16_t	exponent: 15;
	uint16_t	negative: 1;
}	t_dblbits;

typedef union {
	t_dblbits	bits;
	long double	value;
}	t_dbl;

typedef struct {
	t_bigint	*intpart;
	t_bigint	*fracpart;
	int			fracsize;
}	t_guts;

typedef enum {
	none,
	hh,
	h,
	l,
	ll,
	L,
	j,
	z
}	t_length;

typedef struct {
	uint8_t		left:1;
	uint8_t		plus:1;
	uint8_t		space:1;
	uint8_t		zero:1;
	uint8_t		alter:1;
	uint8_t		sign:1;
	uint8_t		negative:1;
	uint8_t		uppercase:1;
	int			width;
	int			precision;
	t_length	modifier;
}	t_flag;

typedef void	(*t_specfn)(char **, char, t_flag *, va_list);

void			print_percent(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_signed(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_unsigned(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_pointer(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_float(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_string(char **buf, char fmt, t_flag *flags, va_list ap);
void			print_char(char **buf, char fmt, t_flag *flags, va_list ap);

void			parse_fmt(const char **fmt, t_flag *flags, va_list ap);
void			buf_copy(char **buf, const char *s, int len, t_flag *flags);

int				get_atoi(const char **fmt);
void			get_width(const char **fmt, t_flag *flags, va_list ap);
void			get_precision(const char **fmt, t_flag *flags, va_list ap);
void			get_modifier(const char **fmt, t_flag *flags);
void			get_flags(const char **fmt, t_flag *flags);

size_t			get_blen(t_bigint *bi);
t_bigint		*calc_intpart(int64_t power, uint64_t mantissa);
t_bigint		*calc_fracpart(int64_t power, uint64_t mantissa);
void			calc_guts(const t_dbl *dbl, t_guts *guts);
void			buf_bigint(char **buf, t_bigint *bi);
void			buf_guts(char **buf, t_guts *guts, t_flag *flags);
void			buf_prefix(char **buf, t_flag *orig, int len);
void			buf_special(char **buf, char *s, t_flag *flags);

int				get_prefix(char *prefix, t_flag *flags, int base);
void			memset_leap(char **buf, int pad, int width);
void			zero(char **buf, int base, t_flag *flags);
void			number(char **buf, uintmax_t num, int base, t_flag *flags);

#endif

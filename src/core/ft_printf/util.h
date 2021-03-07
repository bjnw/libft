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
# include <stddef.h>
# include <stdint.h>

# include "bigint.h"

# define BUFF_SIZE	4096

# define ON		1
# define OFF	0
# define UNDEF	-1

# define VALID_FLAGS	"-+ 0123456789#*.lLhjz"
# define FLAGS_LEN		(sizeof(VALID_FLAGS) - 1)

# define LDBL_BIAS			16382
# define LDBL_MANTISSA_BIT	64

typedef struct s_dblbits	t_dblbits;
typedef union u_dbl			t_dbl;
typedef struct s_guts		t_guts;
typedef enum e_length		t_length;
typedef struct s_flags		t_flags;

typedef void				(*t_specfn)(char **, char, t_flags *, va_list);

struct	s_dblbits {
	uint64_t	mantissa : 64;
	uint16_t	exponent : 15;
	uint16_t	negative : 1;
};

union	u_dbl {
	t_dblbits	bits;
	long double	value;
};

struct	s_guts {
	t_bigint	*intpart;
	t_bigint	*fracpart;
	int			fracsize;
};

enum	e_length {
	none,
	hh,
	h,
	l,
	ll,
	L,
	j,
	z
};

struct	s_flags {
	int			width;
	int			precision;
	t_length	modifier;
	bool		left : 1;
	bool		plus : 1;
	bool		space : 1;
	bool		zero : 1;
	bool		alter : 1;
	bool		sign : 1;
	bool		negative : 1;
	bool		uppercase : 1;
};

void		print_percent(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_signed(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_unsigned(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_pointer(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_float(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_string(char **buf, char fmt, t_flags *flags, va_list ap);
void		print_char(char **buf, char fmt, t_flags *flags, va_list ap);

void		parse_fmt(const char **fmt, t_flags *flags, va_list ap);
void		buf_copy(char **buf, const char *s, int len, t_flags *flags);

int			get_atoi(const char **fmt);
void		get_width(const char **fmt, t_flags *flags, va_list ap);
void		get_precision(const char **fmt, t_flags *flags, va_list ap);
void		get_modifier(const char **fmt, t_flags *flags);
void		get_flags(const char **fmt, t_flags *flags);

int			get_blen(t_bigint *bi);
t_bigint	*calc_intpart(int64_t power, uint64_t mantissa);
t_bigint	*calc_fracpart(int64_t power, uint64_t mantissa);
void		calc_guts(const t_dbl *dbl, t_guts *guts);
void		buf_bigint(char **buf, t_bigint *bi);
void		buf_guts(char **buf, t_guts *guts, t_flags *flags);
void		buf_prefix(char **buf, t_flags *orig, int len);
void		buf_special(char **buf, char *s, t_flags *flags);

int			get_prefix(char *prefix, t_flags *flags, int base);
void		memset_leap(char **buf, int pad, int width);
void		zero(char **buf, int base, t_flags *flags);
void		number(char **buf, uintmax_t num, int base, t_flags *flags);

#endif

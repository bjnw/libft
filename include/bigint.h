/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define BI_COMPS		550
# define BI_COMP_LEN	9

typedef struct s_bigint	t_bigint;

typedef uintptr_t		t_comp;

struct	s_bigint {
	size_t	size;
	bool	negative;
	t_comp	comps[BI_COMPS];
};

t_bigint	*bi_new(void);
t_bigint	*bi_clone(const t_bigint *bi);
void		bi_copy(t_bigint *dst, const t_bigint *src);
void		bi_set(t_bigint *bi, uintmax_t i);
void		bi_destroy(t_bigint *bi);

void		bi_print(const t_bigint *bi);
void		bi_import(t_bigint *bi, const char *s);
void		bi_export(char *s, const t_bigint *bi);

bool		bi_isnull(const t_bigint *bi);
int			bi_cmp(const t_bigint *a, const t_bigint *b);

void		bi_add(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_sub(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_mul(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_pow(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_div(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_mod(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_inc(t_bigint *bi);
void		bi_dec(t_bigint *bi);

void		bi_iadd(t_bigint *bi, uintmax_t i);
void		bi_isub(t_bigint *bi, uintmax_t i);
void		bi_imul(t_bigint *bi, uintmax_t i);
void		bi_ipow(t_bigint *bi, uintmax_t i);
void		bi_idiv(t_bigint *bi, uintmax_t i);
void		bi_imod(t_bigint *bi, uintmax_t i);
void		bi_isqrt(const t_bigint *a, t_bigint *b);

void		bi_and(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_or(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_xor(const t_bigint *a, const t_bigint *b, t_bigint *c);
void		bi_lsh(t_bigint *bi, uintmax_t i);
void		bi_rsh(t_bigint *bi, uintmax_t i);

#endif

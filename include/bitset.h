/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:23:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSET_H
# define BITSET_H

# include <stddef.h>

typedef struct s_bitset	t_bitset;

t_bitset	*bitset_new(size_t nbits);
t_bitset	*bitset_wrap(void *data, size_t nbits);
void		*bitset_unwrap(t_bitset *bset);
void		bitset_resize(t_bitset *bset, size_t newbits);
void		bitset_clear(t_bitset *bset);
void		bitset_destroy(t_bitset *bset);

int			bitset_test(const t_bitset *bset, size_t pos);
void		bitset_set(t_bitset *bset, size_t pos);
void		bitset_put(t_bitset *bset, size_t pos, int val);
void		bitset_reset(t_bitset *bset, size_t pos);
void		bitset_flip(t_bitset *bset, size_t pos);

void		bitset_not(t_bitset *bset);
void		bitset_or(t_bitset *lhs, const t_bitset *rhs);
void		bitset_xor(t_bitset *lhs, const t_bitset *rhs);
void		bitset_and(t_bitset *lhs, const t_bitset *rhs);
void		bitset_andnot(t_bitset *lhs, const t_bitset *rhs);
int			bitset_eq(t_bitset *lhs, const t_bitset *rhs);

#endif

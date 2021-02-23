/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractseq.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTSEQ_H
# define ABSTRACTSEQ_H

# include "collection/abstractobj.h"

/*
** TODO
** void	*merge(const t_obj *a, const t_obj *b);
** void	*uniq(const t_obj *seq, t_cmp cmp);
** void	*distinct(const t_obj *seq, t_cmp cmp);
*/

void	*find(const t_obj *seq, const void *value, t_cmp cmp);
void	*find_r(const t_obj *seq, const void *value,
			t_cmp_r cmp, const void *ctx);
ssize_t	count(const t_obj *seq, t_pred p);
ssize_t	count_r(const t_obj *seq, t_pred_r p, const void *ctx);
ssize_t	indexof(const t_obj *seq, const void *value, t_cmp cmp);
ssize_t	indexof_r(const t_obj *seq, const void *value,
			t_cmp_r cmp, const void *ctx);
void	patch(t_obj *dst, const t_obj *src, ssize_t from, ssize_t count);

#endif

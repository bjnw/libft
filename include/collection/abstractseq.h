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
** void	*flatten(const t_obj *obj);
** void	*merge(const t_obj *a, const t_obj *b);
** void	*uniq(const t_obj *seq, int (*cmp)(const void *, const void *));
** void	*distinct(const t_obj *seq, int (*cmp)(const void *, const void *));
*/

void	*find(const t_obj *seq, const void *value,
			int (*cmp)(const void *, const void *));
void	*find_r(const t_obj *seq, const void *value, const void *ctx,
			int (*cmp)(const void *, const void *, const void *));
ssize_t	count(const t_obj *seq, bool (*p)(const void *));
ssize_t	count_r(const t_obj *seq, const void *ctx,
			bool (*p)(const void *, const void *));
ssize_t	indexof(const t_obj *seq, const void *value,
			int (*cmp)(const void *, const void *));
ssize_t	indexof_r(const t_obj *seq, const void *value, const void *ctx,
			int (*cmp)(const void *, const void *, const void *));

#endif

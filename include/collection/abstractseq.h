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

void	*find(const t_obj *obj, const void *value,
			int (*cmp)(const void *, const void *));
ssize_t	count(const t_obj *obj, const void *value,
			int (*cmp)(const void *, const void *));
ssize_t	locate(const t_obj *obj, const void *value,
			int (*cmp)(const void *, const void *));
void	*find_r(const t_obj *obj, const void *value, void *ctx,
			int (*cmp)(void *, const void *, const void *));
ssize_t	count_r(const t_obj *obj, const void *value, void *ctx,
			int (*cmp)(void *, const void *, const void *));
ssize_t	locate_r(const t_obj *obj, const void *value, void *ctx,
			int (*cmp)(void *, const void *, const void *));

#endif

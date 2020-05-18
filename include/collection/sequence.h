/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

#include "collection/generic.h"

void	*search(const t_obj *obj, const void *val,
			int (*cmp)(const void *, const void *));
ssize_t	count(const t_obj *obj, const void *val,
			int (*cmp)(const void *, const void *));
ssize_t	locate(const t_obj *obj, const void *val,
			int (*cmp)(const void *, const void *));
void	*search_r(const t_obj *obj, const void *val, void *ctx,
			int (*cmp)(const void *, const void *, void *));
ssize_t	count_r(const t_obj *obj, const void *val, void *ctx,
			int (*cmp)(const void *, const void *, void *));
ssize_t	locate_r(const t_obj *obj, const void *val, void *ctx,
			int (*cmp)(const void *, const void *, void *));

#endif
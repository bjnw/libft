/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAKEOBJ_H
# define TAKEOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

struct	s_iterator_state {
	void	*inner;
	long	count;
	t_pred	pred;
};

void	*take_iter(void *(*next)(t_obj *),
			const t_obj *obj, long n, t_pred p);
void	*take_next(t_obj *it);
void	*takewhile_next(t_obj *it);

void	inner_clear(t_obj *it);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermapobj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERMAPOBJ_H
# define FILTERMAPOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"
# include "collection/internal/meta.h"

struct	s_iterator_state {
	void		*inner;
	const void	*func;
	const void	*arg;
	void		*item[];
};

void	*filtermap_iter(void *(*next)(t_obj *),
			const t_obj *obj, void *func, const void *arg);
void	*map_next(t_obj *it);
void	*map_next_r(t_obj *it);
void	*filter_next(t_obj *it);
void	*filter_next_r(t_obj *it);
void	*filternot_next(t_obj *it);
void	*filternot_next_r(t_obj *it);
void	*filtermap_next(t_obj *it);
void	*filtermap_next_r(t_obj *it);

void	inner_clear(t_obj *it);

#endif

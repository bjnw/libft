/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flattenobj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLATTENOBJ_H
# define FLATTENOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"
# include "collection/internal/meta.h"

struct	s_iterator_state {
	void		*innera;
	void		*innerb;
	const void	*func;
	const void	*arg;
	void		*item[];
};

void	*flatten_iter(void *(*next)(t_obj *),
			const t_obj *obj, void *func, const void *arg);
void	*flatten_next(t_obj *it);
void	*flatmap_next(t_obj *it);
void	*flatmap_next_r(t_obj *it);

void	innerab_clear(t_obj *it);

#endif

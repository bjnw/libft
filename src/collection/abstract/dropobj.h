/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DROPOBJ_H
# define DROPOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

struct	s_iterator_state {
	void	*inner;
	t_pred	pred;
};

void	*dropwhile_iter(const t_obj *obj, t_pred p);
void	*dropwhile_next(t_obj *it);

void	*inner_next(t_obj *it);
void	inner_clear(t_obj *it);

#endif

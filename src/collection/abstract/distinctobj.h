/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinctobj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTINCTOBJ_H
# define DISTINCTOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

struct	s_iterator_state {
	t_obj	*inner;
	t_cmp	cmp;
	void	*item;
};

void	*distinct_iter(const t_obj *seq, t_cmp cmp);
void	*distinct_next(t_obj *it);

void	inner_clear(t_obj *it);

#endif

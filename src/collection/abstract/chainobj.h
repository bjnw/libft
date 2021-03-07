/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainobj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINOBJ_H
# define CHAINOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

struct	s_iterator_state {
	void	*innera;
	void	*innerb;
};

void	*chain_iter(const t_obj *a, const t_obj *b);
void	*chain_next(t_obj *it);

void	innerab_clear(t_obj *it);

#endif

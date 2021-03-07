/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zipobj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZIPOBJ_H
# define ZIPOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

struct	s_iterator_state {
	void	*innera;
	void	*innerb;
	void	*def;
	t_pair	pair;
};

void	*zip_iter(void *(*next)(t_obj *),
			const t_obj *a, const t_obj *b, const void *def);
void	*zip_next(t_obj *it);
void	*zipall_next(t_obj *it);

void	*unzip_iter(t_obj *itzip);
void	*unzip_next(t_obj *it);

void	innerab_clear(t_obj *it);

#endif

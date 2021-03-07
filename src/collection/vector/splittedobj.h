/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splittedobj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTEDOBJ_H
# define SPLITTEDOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"
# include "collection/internal/meta.h"

struct	s_iterator_state {
	const char	*s;
	const char	*delim;
	void		(*f)(void *, const char *, const char *);
	void		*item[];
};

void	*splitted_next(t_obj *it);

#endif

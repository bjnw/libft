/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "collection/abstract.h"

typedef t_obj	t_vector;

void	*tovector(const t_obj *obj);
void	*vector(size_t itemsize);
void	*stream(void *data, long size, size_t itemsize);

void	*toslice(void *base, long from, long until, size_t itemsize);
void	*slice(t_obj *vect, long from, long until);
void	*sliced(t_obj *vect, long from, long until);

void	*split(const char *s, const char *delim, size_t itemsize,
			void (*f)(void *, const char *, const char *));
void	*splitted(const char *s, const char *delim, size_t itemsize,
			void (*f)(void *, const char *, const char *));

void	*wrap(void *data, long size, size_t itemsize);
void	*unwrap(t_obj *vect);

void	*view(t_obj *vect, long from, long count, long step);

void	*reversed(t_obj *vect);

void	reverse(t_obj *vect);
void	sort(t_obj *vect, t_cmp cmp);

void	*binsearch(const t_obj *vect, const void *key, t_cmp cmp);

void	*emplace(t_obj *vect, t_f2s_r f, const void *arg);
void	*insert(t_obj *vect, long index, ...);
void	*pop(t_obj *vect, long index, void *out);

#endif

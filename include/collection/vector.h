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

# include "collection/abstractseq.h"

void	*tovector(const t_obj *obj);
void	*vector(size_t itemsize);
void	*stream(void *data, ssize_t size, size_t itemsize);
void	*wrap(void *data, ssize_t size, size_t itemsize);
void	*unwrap(t_obj *vector);
void	*split(const char *s, int delim, size_t itemsize,
			void (*f)(void *, const char *, const char *));
void	*emplace(t_obj *vector, t_f2s_r f, void *ctx);
void	*insert(t_obj *vector, ssize_t index, const void *value);
void	*pop(t_obj *vector, ssize_t index, void *out);
void	*bfind(const t_obj *vector, const void *value, t_cmp cmp);
void	sort(t_obj *vector, t_cmp cmp);
void	reverse(t_obj *vector);

void	*reversed(t_obj *vector);
void	*slice(t_obj *vector, ssize_t from, ssize_t until);
void	*view(t_obj *vector, ssize_t from, ssize_t count, ssize_t step);

#endif

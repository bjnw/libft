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

# include "collection/sequence.h"

void	*tovector(const t_obj *obj);
void	*vector(ssize_t size, size_t itemsize);
void	*wrap(void *data, ssize_t size, size_t itemsize);
void	*unwrap(t_obj *vector);
void	parse(t_obj *dst, const char *s, int delim,
			void (*f)(void *, const char *, const char *));
void	*emplace(t_obj *vector, void *ctx, void (*f)(void *, void *));
void	*insert(t_obj *vector, ssize_t index, const void *val);
void	*pop(t_obj *vector, ssize_t index, void *out);
void	sort(t_obj *vector, int (*cmp)(const void *, const void *));
void	reverse(t_obj *vector);
// void	patch(t_obj *dst, const t_obj *src, ssize_t at);
void	*reversed(t_obj *vector);
void	*stepby(t_obj *vector, ssize_t index, ssize_t step, ssize_t size);
void	*slice(t_obj *vector, ssize_t low, ssize_t high);
void	*take(t_obj *vector, ssize_t size);
void	*drop(t_obj *vector, ssize_t size);
void	*takewhile(t_obj *vector, bool (*p)(const void *));
void	*dropwhile(t_obj *vector, bool (*p)(const void *));

#endif

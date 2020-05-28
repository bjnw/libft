/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "collection/sequence.h"

void	*tolist(const t_obj *obj);
void	*list(ssize_t size, size_t itemsize);
void	*wrap(void *data, ssize_t size, size_t itemsize);
void	*unwrap(t_obj *list);
void	parse(t_obj *dst, const char *s, int delim,
			void (*f)(void *, const char *, const char *));
void	*emplace(t_obj *list, const void *arg,
			void (*f)(void *, const void *));
void	*insert(t_obj *list, ssize_t index, const void *val);
void	*pop(t_obj *list, ssize_t index, void *out);
void	sort(t_obj *list, int (*cmp)(const void *, const void *));
void	reverse(t_obj *list);
// void	patch(t_obj *dst, const t_obj *src, ssize_t at);
void	*reversed(t_obj *list);
void	*stepby(t_obj *list, ssize_t index, ssize_t step, ssize_t size);
void	*slice(t_obj *list, ssize_t low, ssize_t high);
void	*take(t_obj *list, ssize_t size);
void	*drop(t_obj *list, ssize_t size);
void	*takewhile(t_obj *list, bool (*p)(const void *));
void	*dropwhile(t_obj *list, bool (*p)(const void *));

#endif

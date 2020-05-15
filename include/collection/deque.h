/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include "collection/sequence.h"

void	*todeque(const t_obj *obj);
void	*deque(size_t itemsize);
void	*addfirst(t_obj *deque, const void *val);
void	*popfirst(t_obj *deque, void *out);
void	*poplast(t_obj *deque, void *out);
void	*first(const t_obj *deque);
void	*last(const t_obj *deque);

#endif

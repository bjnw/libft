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

# include "collection/abstractseq.h"

void	*tolist(const t_obj *obj);
void	*list(size_t itemsize);
void	*addfirst(t_obj *list, const void *value);
void	*popfirst(t_obj *list, void *out);
void	*poplast(t_obj *list, void *out);
void	*first(const t_obj *list);
void	*last(const t_obj *list);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refcnt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFCNT_H
# define REFCNT_H

# include <stddef.h>

void	*ref(const void *ptr);
void	*unref(const void *ptr);
size_t	refcnt(const void *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractobj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTOBJ_H
# define ABSTRACTOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"
# include "collection/internal/meta.h"

void	putbyte(void *dst, va_list ap, const t_meta *meta);
void	putword(void *dst, va_list ap, const t_meta *meta);
void	putdword(void *dst, va_list ap, const t_meta *meta);
void	putqword(void *dst, va_list ap, const t_meta *meta);
void	putbyref(void *dst, va_list ap, const t_meta *meta);

#endif

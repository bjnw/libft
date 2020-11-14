/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "filtermapitobj.h"

void	*filtermap(const t_obj *obj, t_f1 f)
{
	return (fm_itobj(obj, filtermap_next, NULL, f));
}

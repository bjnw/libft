/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

t_pair	span(const t_obj *obj, t_pred p)
{
	t_pair	pair;

	pair.a = takewhile(obj, p);
	pair.b = dropwhile(obj, p);
	return (pair);
}

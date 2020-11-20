/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "takedropobj.h"

#include <stdlib.h>

void	take_clear(t_obj *obj)
{
	t_itobj *it;

	it = (void *)obj;
	if (it->nested)
		take_clear(it->nested);
	free(it->nested);
}

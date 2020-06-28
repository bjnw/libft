/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bigint.h"

/*
** TODO #ifdef BI_DYNAMIC etc
** free(bi->comps);
*/

void	bi_delete(t_bigint *bi)
{
	free(bi);
}

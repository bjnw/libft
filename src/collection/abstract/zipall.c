/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zipall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*zipall(const t_obj *a, const t_obj *b, const void *def)
{
	return (zip_iter(zipall_next, a, b, def));
}

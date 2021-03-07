/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

t_putfn	opt_put(size_t itemsize)
{
	static t_putfn	fn[] = {
		NULL,
		putbyte, putword, putbyref, putdword,
		putbyref, putbyref, putbyref, putqword,
	};

	if (itemsize <= sizeof(long))
		return (fn[itemsize & 0b1111]);
	return (putbyref);
}

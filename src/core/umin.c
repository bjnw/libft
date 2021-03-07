/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:16:33 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/21 19:16:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** return (a ^ ((a ^ b) & -(a < b)));
*/

uintmax_t	umin(uintmax_t a, uintmax_t b)
{
	if (a <= b)
		return (a);
	return (b);
}
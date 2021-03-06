/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*min_long(void *a, void *b)
{
	if (*(long *)a <= *(long *)b)
		return (a);
	return (b);
}

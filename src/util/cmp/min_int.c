/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*min_int(void *a, void *b)
{
	if (*(int *)a <= *(int *)b)
		return (a);
	return (b);
}
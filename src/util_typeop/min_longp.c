/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_longp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*min_longp(void *a, void *b)
{
	return (*(long *)a <= *(long *)b ? a : b);
}

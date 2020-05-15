/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:27:51 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:27:51 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "Linear Congruential Generator"
*/

static unsigned g_seed;

void	ft_srand(int seed)
{
	g_seed = seed;
}

int		ft_rand(void)
{
	g_seed = 214013 * g_seed + 2531011;
	return (g_seed >> 16 & 0x7FFF);
}

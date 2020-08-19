/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloca.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOCA_H
# define MALLOCA_H

# define ERR_INVAL "malloca: invalid argument"

typedef struct s_meta	t_meta;
struct	s_meta {
	void	*next;
	void	*ctx;
	void	(*dtor)(void *);
	void	*data[];
};

# define META_SIZE	sizeof(t_meta)

#endif

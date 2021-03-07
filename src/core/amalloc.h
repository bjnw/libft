/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMALLOC_H
# define AMALLOC_H

# define E_INVAL "amalloc: invalid argument"

typedef struct s_meta	t_meta;

struct	s_meta {
	void	*next;
	void	*ctx;
	void	(*func)(void *);
	void	*data[];
};

# define META_SIZE	sizeof(t_meta)

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractmeta.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTMETA_H
# define ABSTRACTMETA_H

# ifndef ABSTRACTOBJ_H
#  error "This file is for internal use only"
# endif

# include <sys/types.h>
# include <stddef.h>

/*
** NOTE order is important!
*/
struct	s_object_meta {
	size_t	itemsize;
	ssize_t	size;
};

#endif

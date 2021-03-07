/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:46:04 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 07:54:04 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

void	panic(const char *msg, ...)
{
	va_list	ap;

	va_start(ap, msg);
	ft_vdprintf(STDERR_FILENO, msg, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

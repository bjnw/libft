/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:33:12 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/16 09:02:35 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "fifo.h"

#define BUFSIZE	4096

static char	*joinlines(t_fifo *lines, size_t nbytes)
{
	char	*dst;
	char	*src;
	char	*p;

	dst = xmalloc(nbytes + 1);
	p = dst;
	while (!fifo_isempty(lines))
	{
		fifo_poll(lines, &src);
		p = ft_stpcpy(p, src);
		free(src);
	}
	fifo_destroy(lines);
	return (dst);
}

char	*readfile(const char *path)
{
	t_fifo	*lines;
	char	*buf;
	size_t	nbytes;
	ssize_t	n;
	int		fd;

	fd = open(path, O_RDONLY);
	except(fd < 0, "error: couldn't open file '%s'", path);
	lines = fifo_new(sizeof(char *));
	nbytes = 0;
	while (true)
	{
		buf = ft_strnew(BUFSIZE);
		fifo_add(lines, &buf);
		n = read(fd, buf, BUFSIZE);
		nbytes += n;
		if (n < BUFSIZE)
			break ;
	}
	except(n < 0, "error: couldn't read file '%s'", path);
	close(fd);
	return (joinlines(lines, nbytes));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRBUF_H
# define STRBUF_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_strbuf	t_strbuf;

t_strbuf	*strbuf_new(void);
void		strbuf_add(t_strbuf *strbuf, const char *s);
void		strbuf_dup(t_strbuf *strbuf, const char *src);
void		strbuf_fmt(t_strbuf *strbuf, const char *fmt, ...);
void		strbuf_chars(const char *s, size_t offset, size_t len);
bool		strbuf_isempty(const t_strbuf *strbuf);
void		strbuf_iter(t_strbuf *strbuf, void (*func)(void *));
char		*strbuf_join(const t_strbuf *strbuf);
void		strbuf_destroy(t_strbuf *strbuf);

#endif

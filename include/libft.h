/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:39:51 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 22:11:58 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef unsigned char	*t_addr;

int			ft_isascii(int c);
int			ft_iscntrl(int c);
int			ft_isgraph(int c);
int			ft_ispunct(int c);
int			ft_isdigit(int c);
int			ft_isxdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isspace(int c);
int			ft_isblank(int c);
int			ft_isprint(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_toascii(int c);

uintmax_t	ft_abs(intmax_t n);
intmax_t	ft_imin(intmax_t a, intmax_t b);
intmax_t	ft_imax(intmax_t a, intmax_t b);
uintmax_t	ft_umin(uintmax_t a, uintmax_t b);
uintmax_t	ft_umax(uintmax_t a, uintmax_t b);
intmax_t	ft_atoi(const char *s);
uintmax_t	ft_atou(const char *s);
char		*ft_itoa(char *s, intmax_t n);
char		*ft_utoa(char *s, uintmax_t n);
unsigned	ft_intlen(intmax_t n);

uint32_t	ft_hash(uint32_t data);
void		ft_srand(int seed);
int			ft_rand(void);

void		*xmalloc(size_t size);
void		*xcalloc(size_t nmemb, size_t size);
void		*xrealloc(void *data, size_t newsize, size_t oldsize);

void		*gc_malloc(size_t size);
void		gc_sweep(const void *scope);
void		gc_finalize(void);

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_mempset(void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_mempcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memdup(const void *s, size_t n);
void		ft_memswap(void *restrict s1, void *restrict s2, size_t n);
void		*ft_memdel(void **ptr);
void		*ft_memdelpv(void **ptr);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcasecmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
char		*ft_stpcpy(char *dst, const char *src);
char		*ft_stpncpy(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t n);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strlwr(char *s);
char		*ft_strupr(char *s);

char		*ft_strnew(size_t len);
char		*ft_strjmp(const char **sp, int delim);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strrev(char *s);
char		**ft_strsplit(const char *s, int delim);
char		*ft_strsub(const char *s, unsigned from, size_t n);
char		*ft_strtrim(const char *s);
size_t		ft_strelems(const char *s, int delim);
char		*ft_strsep(char **sp, int delim);

void		ft_putstr(const char *s);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl(const char *s);
void		ft_putendl_fd(const char *s, int fd);

void		ft_qsort(void *data, size_t len, size_t size,
				int (*cmp)(const void *, const void *));
void		ft_foreach(void *data, size_t len, size_t size,
				void (*f)(void *));
void		*ft_map(const void *data, size_t len, size_t size,
				void (*f)(void *));

void		panic(const char *msg);

#endif

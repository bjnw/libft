#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "libft.h"
#include "collection/vector.h"
#include "collection/list.h"

void	myatoi(void *item, const char *begin, const char *end)
{
	(void)end;
	*(int *)item = ft_atoi(begin);
}

bool	num_filter(const void *item)
{
	return (*(int *)item % 7 == 0);
}

bool	num_pos(const void *item)
{
	return (*(int *)item >= 0);
}

void	num_mul1000(void *item)
{
	*(int *)item *= 1000;
}

void	num_print(void *item)
{
	printf("[%10d]\n", *(int *)item);
}

void	*num_max(void *v1, void *v2)
{
	return (*(int *)v1 > *(int *)v2 ? v1 : v2);
}

void	*num_min(void *v1, void *v2)
{
	return (*(int *)v1 < *(int *)v2 ? v1 : v2);
}

void	*num_sum(void *sum, void *item)
{
	*(intmax_t *)sum += *(int *)item;
	return (sum);
}

void	str_cut(void *dst, const char *begin, const char *end)
{
	size_t len = end - begin;
	*(char **)dst = ft_strndup(begin, len);
}

void	str_upper(void *item)
{
	ft_strupr(*(char**)item);
}

void	str_print(void *s)
{
	printf("> %s <\n", *(char **)s);
}

void	str_free(void *s)
{
	free(*(char **)s);
}

void	str_dup(void *item, const void *s)
{
	*(char **)item = ft_strdup(s);
}

typedef struct {
	int		i;
	char	c;
}	t_struct;

void	lst_print(void *item)
{
	t_struct *st = item;
	printf("-> c = %c, i = %d\n", st->c, st->i);
}

void	lst_fn(void *item)
{
	t_struct *st = item;
	st->c = ft_toupper(st->c);
	st->i -= 100;
}

int		obj_cmp(void *item1, void *item2)
{
	return (memcmp(item1, item2, sizeof(t_struct)));
}

// __attribute__((noinline))
// void	mt()
// {
// 	void *p1 = malloca(10);
// 	void *p3 = malloca(10);
// 	void *p4 = malloca(10);
// }

#define TIME_DIFF(a,b) ((double)(b - a) / CLOCKS_PER_SEC)

int		main(void)
{
	const ssize_t n = 10000000;
	clock_t begin, end;
	int *val;
	void *item;
	void *it;

	// void *p1 = malloca(100);
	// mt();
	// void *p2 = malloca(100);
	// mt();
	// void *p3 = malloca(100);
	// mt();
	// void *p4 = malloca(100);
	// malloca_finalize();
/*
	// void *num = split(num,
	// 	"42,000,1,2,3,4,     5,6,7,8  ,9,    10"
	// 	",,,,  00123,  +456   ,7890  ,-_-, zzz,"
	// 	"-666,     1234567890,  ,,NaN,,-10000,,",
	// 	',',
	// 	sizeof(int),
	// 	myatoi
	// );

	// void *td = tolist(num);
	// extend(td, num);
	// foreach(td, num_print);

	void *lst = list(sizeof(t_struct));

	begin = clock();
	for (ssize_t i = 0; i < n; i++) {
		add(lst, &(t_struct){100, 'a'});
		addfront(lst, &(t_struct){200, 'b'});
	}
	end = clock();
	// foreach(lst, lst_fn);
	// foreach(lst, lst_print);
	printf("lst added items,  %fs\n", TIME_DIFF(begin, end));
	printf("lst size: %ld\n", size(lst));

	// begin = clock();
	// for (ssize_t i = 0, z = 1; i < size(lst); i++, z *= -1) {
	// 	item = get(lst, i * z);
	// }
	// end = clock();
	// printf("accessed (rand) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0; i < size(lst); i++) {
	// 	item = get(lst, i);
	// }
	// end = clock();
	// printf("accessed (cons) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));

	// it = iter(lst);
	// begin = clock();
	// while ((item = next(it))) {
	// 	val = item;
	// }
	// end = clock();
	// printf("accessed (iter) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0, z = 1; i < size(lst); i++, z *= -1) {
	// 	set(lst, i * z, &(t_struct){i, 'r'});
	// }
	// end = clock();
	// // foreach(lst, num_print);
	// printf("updated (rand) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0; i < size(lst); i++) {
	// 	set(lst, i, &(t_struct){i, 'c'});
	// }
	// end = clock();
	// // foreach(lst, num_print);
	// printf("updated (cons) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));

	// it = iter(lst);
	// int x = 0;
	// begin = clock();
	// while ((val = next(it))) {
	// 	*(t_struct *)val = (t_struct){x++, 'a' + x % 26};
	// }
	// end = clock();
	// // foreach(lst, num_print);
	// printf("updated (iter) %ld items, %fs\n", size(lst), TIME_DIFF(begin, end));


	t_struct st;
	begin = clock();
	for (ssize_t i = 0, sz = size(lst) / 2 - 10; i < sz; i++) {
		popfront(lst, &st);
		popback(lst, &st);
	}
	end = clock();
	printf("lst poped items,  %fs\n", TIME_DIFF(begin, end));
	printf("lst size: %ld\n", size(lst));

	foreach(lst, lst_print);

	// item = get(lst, -1l);
	// lst_print(item);
	delete(lst);

// */
// /**
	void *num = split(
		"42,000,1,2,3,4,     5,6,7,8  ,9,    10"
		",,,,  00123,  +456   ,7890  ,-_-, zzz,"
		"-666,     1234567890,  ,,NaN,,-10000,,",
		',',
		sizeof(int),
		myatoi
	);
	foreach(num, num_print);
	printf("num ints splitted\n");
	printf("num size: %ld\n", size(num));

	it = takewhile(num, num_pos);
	foreach(it, num_print);
	printf("num positive taked\n");

	it = dropwhile(num, num_pos);
	foreach(it, num_print);
	printf("num positive dropped\n");

	// it = iter(num);
	// void *mpn = map(it, num_mul1000);
	// foreach(mpn, num_print);
	// printf("mpn size: %ld\n", size(mpn));
	// delete(mpn);

	it = reversed(num);
	it = drop(it, 10);
	patch(num, it, 0);
	foreach(num, num_print);
	printf("num patched\n");

	begin = clock();
	for (ssize_t i = 0; i < n; i++) {
		add(num, &i);
	}
	end = clock();
	// foreach(num, num_print);
	printf("num added %ld items,  %fs\n", n, TIME_DIFF(begin, end));
	printf("num size: %ld\n", size(num));

	val = reduce(num, num_min);
	printf("num min=%d\n", *val);
	val = reduce(num, num_max);
	printf("num max=%d\n", *val);
	intmax_t sum = 0;
	sum = *(intmax_t *)fold(num, &sum, num_sum);
	printf("num sum=%ld\n", sum);

	begin = clock();
	foreach(num, num_mul1000);
	end = clock();
	printf("f applied for %ld items, %fs\n", n, TIME_DIFF(begin, end));

	begin = clock();
	reverse(num);
	end = clock();
	// foreach(num, num_print);
	printf("reversed %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, z = 1; i < size(num); i++, z *= -1) {
		val = get(num, i * z);
	}
	end = clock();
	printf("accessed (rand) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0; i < size(num); i++) {
		val = get(num, i);
	}
	end = clock();
	printf("accessed (cons) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	it = iter(num);
	begin = clock();
	while ((item = next(it))) {
		val = item;
	}
	end = clock();
	printf("accessed (iter) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, z = 1; i < size(num); i++, z *= -1) {
		set(num, i * z, &i);
	}
	end = clock();
	// foreach(num, num_print);
	printf("updated (rand) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0; i < size(num); i++) {
		set(num, i, &i);
	}
	end = clock();
	// foreach(num, num_print);
	printf("updated (cons) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	it = iter(num);
	int x = 0;
	begin = clock();
	while ((val = next(it))) {
		*val = x++;
	}
	end = clock();
	// foreach(num, num_print);
	printf("updated (iter) %ld items, %fs\n", size(num), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, m = (size(num) >> 1) + 1; i < m; i++) {
		del(num, -1L);
	}
	end = clock();
	// foreach(num, num_print);
	printf("num removed 1/2 items, %fs\n", TIME_DIFF(begin, end));
	printf("num size: %ld\n", size(num));

	begin = clock();
	void *flt = filter(num, num_filter);
	end = clock();
	// foreach(flt, num_print);
	printf("flt filtered %ld items, %fs\n", size(flt), TIME_DIFF(begin, end));
	printf("flt size: %ld\n", size(flt));


	begin = clock();
	it = slice(flt, 1122, 94780);
	void *sl = collect(it);
	end = clock();
	// foreach(sl, num_print);
	printf("sl sliced %ld items  %fs\n", size(sl), TIME_DIFF(begin, end));
	printf("sl size: %ld\n", size(sl));

	begin = clock();
	for (ssize_t i = 0; i < 100; i++) {
		extend(flt, sl);
	}
	end = clock();
	printf("flt extended 100 times with sl items, %fs\n", TIME_DIFF(begin, end));
	printf("flt size: %ld\n", size(flt));

	// begin = clock();
	// for (ssize_t i = 1; i <= 10000; i++) {
	// 	insert(flt, -i, &i);
	// }
	// end = clock();
	// // foreach(flt, num_print);
	// printf("flt items inserted to -1..-10000, %fs\n", TIME_DIFF(begin, end));
	// printf("flt size: %ld\n", size(flt));

	begin = clock();
	extend(num, flt);
	end = clock();
	printf("num extended with flt items, %fs\n", TIME_DIFF(begin, end));
	printf("num size: %ld\n", size(num));

	it = take(num, 10);
	foreach(reversed(it), num_print);
	it = drop(num, size(num) - 10);
	foreach(it, num_print);

	// del(num, 0);
	// del(num, 0);
	// del(num, 0);
	// del(num, 0);
	// del(num, -1L);
	// del(num, -1L);
	// foreach(num, num_print);
	// delete(sl);

	// for (ssize_t i = 0; i < size(num); i += 100000) {
	// 	intmax_t maxsum = 0;
	// 	it = sliding(num, i, 1, 100);
	// 	fold(it, &maxsum, num_sum);
	// 	num_print(&maxsum);
	// }

	// srand(1111);
	// void *srt = vector(10000000, sizeof(int));
	// for (int i = 0, n; i < 10000000; i++) {
	// 	n = rand() % 10000000;
	// 	add(srt, &n);
	// }
	// begin = clock();
	// // ft_qsort(((t_obj *)srt)->data, ((t_obj *)srt)->size, ((t_obj *)srt)->itemsize, num_cmp);
	// sort(srt, num_cmp);
	// end = clock();
	// // foreach(srt, num_print);
	// printf("srt sorted, %fs\n", TIME_DIFF(begin, end));
	// printf("srt size: %ld\n", size(srt));

	delete(sl);
	delete(flt);
	delete(num);
// **/
/**
	void *str = split(
		"and  again and |again!|    ..   yoji  |"
		"146%|-- @|flamingos/zakatos |(Y)_zzzz_|"
		"GORT!\nKLAATU  BARADA nikto||||!??\v  |"
		"lorem ipsum dolor sit down and shut up "
		"   ooooooo   |    leeeee      |    fin.",
		'|',
		sizeof(char *)
		str_cut
	);
	// setprop_dtor(str, str_free);

	foreach(str, str_upper);
	reverse(str);
	// foreach(str, str_print);

	char *p1, *p2, *p3;
	pop(str, -3, &p1);
	pop(str, -1, &p2);
	pop(str, 2, &p3);
	printf("pop: --- %s ---\n", p1);
	printf("pop: --- %s ---\n", p2);
	printf("pop: --- %s ---\n", p3);
	free(p1);
	free(p2);
	free(p3);
	del(str, 1);
	del(str, -1L);

	emplace(str, "~~dummy!\n", str_dup);
	emplace(str, "Frankly, my dear, I don't give a damn", str_dup);
	emplace(str, "shake your bytes", str_dup);
	char *s = ft_strdup("???update???");
	set(str, 2, &s);

	void *sli = slice(str, 3, 7);
	void *sl = collect(sli);
	foreach(sl, str_print);
	printf("sl size: %ld\n\n", size(sl));

	foreach(str, str_print);
	printf("str upcase, reversed, changed size: %ld\n\n", size(str));

	delete(sl);
	delete(str);
// **/
	return (EXIT_SUCCESS);
}

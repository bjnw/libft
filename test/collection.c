#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include "collection/abstractobj.h"
#include "collection/vector.h"
#include "collection/list.h"
#include "libft.h"
#include "util/typeop.h"

void	myatoi(void *item, const char *begin, const char *end)
{
	(void)end;
	*(int *)item = ft_atoi(begin);
}

bool	int_odd(const void *item)
{
	return (*(int *)item % 2 == 1);
}

bool	int_even(const void *item)
{
	return (*(int *)item % 2 == 0);
}

bool	int_div3(const void *item)
{
	return (*(int *)item % 3 == 0);
}

bool	int_pos(const void *item)
{
	return (*(int *)item > 0);
}

bool	int_neg(const void *item)
{
	return (*(int *)item < 0);
}

bool	int_distinct(void *ctx, const void *item)
{
	int *prev = ctx;
	int n = *(int *)item;

	if (*prev == n)
		return (false);
	*prev = n;
	return (true);
}

void	int_mul100(void *item)
{
	*(int *)item *= 100;
}

void	int_mul1693(void *item)
{
	*(int *)item *= 1693;
}

void	*int_neg_mul1693(void *item)
{
	if (!int_neg(item))
		return (NULL);
	int_mul1693(item);
	return (item);
}

void	int_print(void *item)
{
	printf("[%10d]\n", *(int *)item);
}

void	intzip_print(t_zip *pair)
{
	printf("(%d,%d)\n", *(int *)pair->a, *(int *)pair->b);
}

void	*int_sum(void *sum, void *item)
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
	printf("\" %s \"\n", *(char **)s);
}

void	str_free(void *s)
{
	free(*(char **)s);
}

void	str_dup(void *item, void *s)
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
	printf("{ c = '%c', i = %d }\n", st->c, st->i);
}

void	lst_fn(void *item)
{
	t_struct *st = item;
	st->c = ft_toupper(st->c);
	int_mul1693(&st->i);
}

int		obj_cmp(void *item1, void *item2)
{
	return (ft_memcmp(item1, item2, sizeof(t_struct)));
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
	const ssize_t MAX_ITEMS = 10000000;
	clock_t begin, end;
	int *val;
	void *item;
	void *it;
	intmax_t acc;

	// void *p1 = malloca(100);
	// mt();
	// void *p2 = malloca(100);
	// mt();
	// void *p3 = malloca(100);
	// mt();
	// void *p4 = malloca(100);
	// malloca_finalize();
/*
	// void *ints = split(ints,
	// 	"42,000,1,2,3,4,     5,6,7,8  ,9,    10"
	// 	",,,,  00123,  +456   ,7890  ,-_-, zzz,"
	// 	"-666,     1234567890,  ,,NaN,,-10000,,",
	// 	',',
	// 	sizeof(int),
	// 	myatoi
	// );

	// void *td = tolist(ints);
	// extend(td, ints);
	// foreach(td, int_print);

	void *lst = list(sizeof(t_struct));

	begin = clock();
	for (ssize_t i = 0; i < MAX_ITEMS / 2; i++) {
		add(lst, &(t_struct){1617, 'a'});
		addfirst(lst, &(t_struct){-42, 'Z'});
	}
	end = clock();
	// foreach(lst, lst_fn);
	// foreach(lst, lst_print);
	printf("lst: added %ld items:  %fs\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0, z = 1; i < size(lst); i++, z *= -1) {
	// 	item = get(lst, i * z);
	// }
	// end = clock();
	// printf("lst: accessed (random)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0; i < size(lst); i++) {
	// 	item = get(lst, i);
	// }
	// end = clock();
	// printf("lst: accessed (linear)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	it = iter(lst);
	begin = clock();
	while ((item = next(it))) {
		val = item;
	}
	end = clock();
	printf("lst: accessed (iterate) %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0, z = 1; i < size(lst); i++, z *= -1) {
	// 	set(lst, i * z, &(t_struct){i, 'a' + i % 26});
	// }
	// end = clock();
	// // foreach(lst, int_print);
	// printf("lst: updated (random)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	// begin = clock();
	// for (ssize_t i = 0; i < size(lst); i++) {
	// 	set(lst, i, &(t_struct){i, 'a' + i % 26});
	// }
	// end = clock();
	// // foreach(lst, int_print);
	// printf("lst: updated (linear)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	it = iter(lst);
	int x = 0;
	begin = clock();
	while ((val = next(it))) {
		*(t_struct *)val = (t_struct){x, 'a' + x % 26};
		x++;
	}
	end = clock();
	// foreach(lst, int_print);
	printf("lst: updated (iterate) %ld items:  %fs\n\n", size(lst), TIME_DIFF(begin, end));

	t_struct st;
	begin = clock();
	for (ssize_t i = 0, sz = size(lst) / 2 - 10; i < sz; i++) {
		popfirst(lst, &st);
		poplast(lst, NULL);
	}
	end = clock();
	printf("lst: poped items:  %fs\n", TIME_DIFF(begin, end));
	printf("size(lst): %ld\n", size(lst));

	foreach(lst, lst_print);

	delete(lst);
// */
// /**
	void *ints = split(
		"42,,1,  2,3,4 , 000  ,4, 5,6   ,7,8  ,9,    10"
		",,,,  00123,  +456,   -1122  ,7890  ,-_-, zzz,"
		"  -666,     1234567890,  ,,  NaN,    ,-10000,,",
		',',
		sizeof(int),
		myatoi
	);
	foreach(ints, int_print);
	printf("ints = split(\"42,,1,  2,3 ... \", ',', sizeof(int), myatoi)\n");
	printf("size(ints): %ld\n\n", size(ints));

    begin = clock();
	for (ssize_t i = -10; i <= 10; i++) {
		add(ints, &i);
	}
	end = clock();
	foreach(ints, int_print);
	printf("add(ints, &i) x %ld; i = -10..10:  %fs\n", 20L, TIME_DIFF(begin, end));
	printf("size(ints): %ld\n\n", size(ints));

	foreach(filter(map(filter(ints, int_odd), int_mul1693), int_div3), int_print);
	printf("filter(map(filter(ints, int_odd), int_mul1693), int_div3): %fs\n\n", TIME_DIFF(begin, end));

	foreach(filternot(ints, int_pos), int_print);
	printf("filternot(ints, int_pos)\n");
	acc = 0;
	fold(filternot(ints, int_pos), &acc, int_sum);
	printf("fold(filternot(ints, int_pos), &acc, int_sum): %ld\n\n", acc);

	foreach(takewhile(ints, int_pos), int_print);
	printf("takewhile(ints, int_pos)\n\n");

	foreach(dropwhile(drop(ints, 24), int_neg), int_print);
	printf("dropwhile(drop(ints, 24), int_neg)\n\n");

	foreach(drop(ints, 100), int_print);
	printf("drop(ints, 100)  [nothing]\n\n");

	foreach(drop(ints, 36), int_print);
	printf("drop(ints, 36)\n\n");

	// TODO take/drop/reverse closures
	it = map(map(reversed(drop(ints, size(ints) - 10)), int_mul100), int_mul100);
	// foreach(it, int_print);
	patch(ints, it, 5, 10);
	foreach(take(ints, 20), int_print);
	printf("...\nints: patched items 5..15 with last 10 reversed "
			"mapped (mul100 x 2) items\n(first 20 items printed)\n\n");

	foreach(filtermap(ints, int_neg_mul1693), int_print);
	printf("filtermap(ints, int_neg_mul1693)\n\n");


	begin = clock();
	for (ssize_t i = 0; i < MAX_ITEMS; i++) {
		add(ints, &i);
	}
	end = clock();
	// foreach(ints, int_print);
	printf("add(ints, &i); i = 0..%ld:  %fs\n", MAX_ITEMS, TIME_DIFF(begin, end));
	printf("size(ints): %ld\n\n", size(ints));

	val = reduce(ints, min_intp);
	printf("reduce(ints, min_intp): %d\n", *val);
	val = reduce(ints, max_intp);
	printf("reduce(ints, max_intp): %d\n", *val);
	acc = 0;
	begin = clock();
	fold(ints, &acc, int_sum);
	end = clock();
	printf("fold(ints, &acc, int_sum): %ld\n"
		"average time for fold:  %fs\n\n", acc, TIME_DIFF(begin, end));

	begin = clock();
	foreach(ints, int_mul100);
	end = clock();
	printf("foreach(ints, int_mul100):  %fs\n"
		"size(ints): %ld\n\n", TIME_DIFF(begin, end), size(ints));

	begin = clock();
	reverse(ints);
	end = clock();
	// foreach(ints, int_print);
	printf("reverse(ints):  %fs\n\n", TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, z = 1; i < size(ints); i++, z *= -1) {
		val = get(ints, i * z);
	}
	end = clock();
	printf("ints: accessed (random)  %ld items:  %fs\n", size(ints), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0; i < size(ints); i++) {
		val = get(ints, i);
	}
	end = clock();
	printf("ints: accessed (linear)  %ld items:  %fs\n", size(ints), TIME_DIFF(begin, end));

	it = iter(ints);
	begin = clock();
	while ((item = next(it))) {
		val = item;
	}
	end = clock();
	printf("ints: accessed (iterate) %ld items:  %fs\n\n", size(ints), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, z = 1; i < size(ints); i++, z *= -1) {
		set(ints, i * z, &i);
	}
	end = clock();
	// foreach(ints, int_print);
	printf("ints: updated (random)  %ld items:  %fs\n", size(ints), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0; i < size(ints); i++) {
		set(ints, i, &i);
	}
	end = clock();
	// foreach(ints, int_print);
	printf("ints: updated (linear)  %ld items:  %fs\n", size(ints), TIME_DIFF(begin, end));

	it = iter(ints);
	int x = 0;
	begin = clock();
	while ((val = next(it))) {
		*val = x++;
	}
	end = clock();
	// foreach(ints, int_print);
	printf("ints: updated (iterate) %ld items:  %fs\n\n", size(ints), TIME_DIFF(begin, end));

	begin = clock();
	for (ssize_t i = 0, m = (size(ints) >> 1) + 1; i < m; i++) {
		del(ints, -1L);
	}
	end = clock();
	// foreach(ints, int_print);
	printf("del(ints, -1L) x half size; new size: %ld:  %fs\n\n", size(ints), TIME_DIFF(begin, end));

	begin = clock();
	it = filter(ints, int_even);
	void *flt = collect(it);
	end = clock();
	// foreach(flt, int_print);
	printf("flt = collect(filter(ints, int_even)):  %fs\n"
		"size(flt): %ld\n\n", TIME_DIFF(begin, end), size(flt));


	begin = clock();
	it = slice(flt, 1122, 94780);
	void *sl = collect(it);
	end = clock();
	// foreach(sl, int_print);
	printf("sl = collect(slice(flt, 1122, 94780)):  %fs\n"
		"size(sl): %ld\n\n", TIME_DIFF(begin, end), size(sl));

	begin = clock();
	for (ssize_t i = 0; i < 100; i++) {
		extend(flt, sl);
	}
	end = clock();
	printf("extend(flt, sl) x 100:  %fs\n", TIME_DIFF(begin, end));
	printf("size(flt): %ld\n\n", size(flt));

	// begin = clock();
	// for (ssize_t i = 1; i <= size(flt) / 4; i++) {
	// 	insert(flt, -i, &i);
	// }
	// end = clock();
	// // foreach(flt, int_print);
	// printf("flt: inserted to -1..-%ld:  %fs\n", size(flt) / 4, TIME_DIFF(begin, end));
	// printf("size(flt): %ld\n\n", size(flt));

	begin = clock();
	extend(ints, flt);
	end = clock();
	printf("extend(ints, flt):  %fs\n", TIME_DIFF(begin, end));
	printf("size(ints): %ld\n\n", size(ints));

	// printf("size(flt): %ld, size(ints): %ld\n", size(flt), size(ints));
	// foreach(take(drop(take(ints, 1500), 30), 10), (t_f1s)int_print);
	// foreach(take(drop(ints, 7825), 10), (t_f1s)int_print);
	// foreach(zip(take(flt, 11), take(ints, 10)), (t_f1s)intzip_print);
	foreach(zip(drop(flt, 17), take(drop(ints, 100), 10)), (t_f1s)intzip_print);
	printf("zip(drop(flt, 17), take(drop(ints, 100), 10))\n\n");

	// foreach(take(reversed(ints), 10), int_print);
	// printf("take(reversed(ints), 10)\n\n");

	// foreach(drop(ints, size(ints) - 10), int_print);
	// printf("drop(ints, size(ints) - 10)\n\n");

	// del(ints, 0);
	// del(ints, 0);
	// del(ints, 0);
	// del(ints, -1L);
	// del(ints, -1L);
	// del(ints, -1L);
	// foreach(ints, int_print);

	// intmax_t maxsum = 0;
	// ssize_t slicesize = size(ints) / 7000;
	// for (ssize_t i = 0; i < size(ints); i += slicesize) {
	// 	intmax_t sum = 0;
	// 	it = view(ints, i, slicesize, 1);
	// 	fold(it, &sum, int_sum);
	// 	if (sum > maxsum)
	// 		maxsum = sum;
	// }
	// int_print(&maxsum);
	// printf("ints: maxsum of slice size %ld: %ld\n\n", slicesize, maxsum);

	// srand(0xDEAD);
	// void *srt = vector(sizeof(int));
	// for (int i = 0; i < MAX_ITEMS; i++) {
	// 	int r = rand() % MAX_ITEMS;
	// 	add(srt, &r);
	// }
	// begin = clock();
	// sort(srt, cmp_intp);
	// end = clock();
	// // foreach(srt, int_print);
	// printf("sort(srt, cmp_intp):  %fs\n", TIME_DIFF(begin, end));
	// printf("size(srt): %ld\n\n", size(srt));
	// delete(srt);

	delete(sl);
	delete(flt);
	delete(ints);
// **/
/**
	void *str = split(
		"and  again and |AGAIN!|    ..   yoji  |"
		"146%|-- @|flamingos/zakatos |(Y)_zzzz_|"
		"GORT!\t\tKLAATU  BARADA nikto| ||!??\v|"
		"lorem ipsum dolor sit down and shut up|"
		"   ooooooo |||| no ooo plz    |    fin.",
		'|',
		sizeof(char *),
		str_cut
	);
	setattr_dtor(str, str_free);
	foreach(str, str_print);
	printf("str splitted\n");
	printf("size(str): %ld\n\n", size(str));

	foreach(str, str_upper);
	reverse(str);

	// char *p1, *p2, *p3;
	// pop(str, -3, &p1);
	// pop(str, -1, &p2);
	// pop(str, 2, &p3);
	// printf("pop -3: \" %s \"\n", p1);
	// printf("pop -1: \" %s \"\n", p2);
	// printf("pop 2: \" %s \"\n\n", p3);
	// free(p1); free(p2); free(p3);

	del(str, 3);
	del(str, -4L);

	emplace(str, "~~dummy!\n", str_dup);
	emplace(str, "Frankly, my dear, I don't give a damn", str_dup);
	emplace(str, "shake your bytes", str_dup);
	foreach(str, str_print);
	printf("str: emplaced 3 items\n");
	printf("size(str): %ld\n\n", size(str));

	// char *s = ft_strdup("???update???");
	// set(str, 2, &s);

	void *sl = collect(slice(str, 3, 7));
	foreach(sl, str_print);
	printf("size(sl): %ld\n\n", size(sl));

	foreach(str, str_print);
	printf("str: upcase, reversed, size(changed): %ld\n\n", size(str));

	delete(sl);
	delete(str);
// **/
	return (EXIT_SUCCESS);
}

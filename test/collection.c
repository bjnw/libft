#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include "collection/abstract.h"
#include "collection/vector.h"
#include "collection/list.h"
#include "collection/internal/object.h"
#include "libft.h"
#include "util/cmp.h"

void	myatoi(void *item, const char *start, const char *end)
{
	(void)end;
	*(int *)item = ft_atoi(start);
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

bool	next_gt_prime(const void *item)
{
	int n = *(int *)item;
	static int prev;

	if (n <= (prev * PHI + 0.5))
		return (false);
	prev = n;
	return (true);
}

void	*int_mul100(void *item)
{
	*(int *)item *= 100;
	return (item);
}

void	*int_mul1693(void *item)
{
	*(int *)item *= 1693;
	return (item);
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
	printf("[%11d]\n", *(int *)item);
}

void	intzip_print(t_pair *pair)
{
	printf("(%d,%d)\n", *(int *)pair->a, *(int *)pair->b);
}

void	*int_sum(void *sum, void *item)
{
	*(intmax_t *)sum += *(int *)item;
	return (sum);
}

void	*null_op(void *a, void *b)
{
	(void)a;
	(void)b;
	return (a);
}

void	str_cut(void *dst, const char *start, const char *end)
{
	size_t len = end - start;
	*(char **)dst = ft_strndup(start, len);
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

void	str_dup(const void *arg, void *dst)
{
	*(char **)dst = ft_strdup(arg);
}

void	char_print(void *c)
{
	printf("%c ", *(char *)c);
}

typedef struct {
	void	*ptr;
	int		i;
	char	c;
}	t_struct;

void	struct_print(void *item)
{
	t_struct *st = item;
	printf("{ c = '%c', i = %d }\n", st->c, st->i);
}

void	*map_struct_i(void *item)
{
	t_struct *data = item;
	return (&data->i);
}

void	*map_struct_c(void *item)
{
	t_struct *data = item;
	data->c = ft_toupper(data->c);
	return (&data->c);
}

int		cmp_struct(void *item1, void *item2)
{
	return (ft_memcmp(item1, item2, sizeof(t_struct)));
}

void	lst_fn(void *item)
{
	t_struct *st = item;
	st->c = (ft_toupper(st->c) + 1) & 127;
	int_mul1693(&st->i);
}

void	void_func(void *item)
{
	(void)item;
}

void	void_r_func(const void *ctx, void *item)
{
	(void)ctx;
	(void)item;
}

bool	pred_func(const void *item)
{
	(void)item;
	return (true);
}

bool	pred_r_func(const void *ctx, const void *item)
{
	(void)ctx;
	(void)item;
	return (true);
}

// #define ITEMS	500000000L
#define ITEMS	100000000L
// #define ITEMS	10000000L
// #define ITEMS	100000L
// #define ITEMS	1000L

#define TIME_DIFF(a,b) ((double)(b - a) / CLOCKS_PER_SEC)
#include "bitset.h"
int		main(void)
{
	clock_t start, end;
	int *val;
	void *item;
	void *it;
	intmax_t acc;

/*
// 	void *ints = split(
// 		"42,000,1,2,3,4,     5,6,7,8  ,9,    10"
// 		",,,,  00123,  +456   ,7890  ,-_-, zzz,"
// 		"-666,     1234567890,  ,,NaN,,-10000,,",
// 		",",
// 		sizeof(int),
// 		myatoi
// 	);
// 	void *td = tolist(ints);
// 	extend(td, ints);
// 	foreach(td, int_print);

	void *lst = list(sizeof(int));
	start = clock();
	for (long i = 0; i < ITEMS / 2; i++) {
		add(lst, i);
		addfirst(lst, i * 2);
	}
	end = clock();
	foreach(lst, int_print);
	printf("lst: added %ld items:  %fs\n", size(lst), TIME_DIFF(start, end));

// 	void *lst = list(sizeof(t_struct));
// 	start = clock();
// 	for (long i = 0; i < ITEMS / 2; i++) {
// 		add(lst, (t_struct){NULL, 1617, 'a'});
// 		addfirst(lst, (t_struct){NULL,-42, 'Z'});
// 	}
// 	end = clock();
// 	foreach(lst, lst_fn);
// 	foreach(lst, struct_print);
// 	printf("lst: added %ld items:  %fs\n", size(lst), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0, z = 1; i < size(lst); i++, z *= -1) {
		item = get(lst, i * z);
	}
	end = clock();
	printf("lst: accessed (random)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0; i < size(lst); i++) {
		item = get(lst, i);
	}
	end = clock();
	printf("lst: accessed (linear)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

	it = iter(lst);
	start = clock();
	while ((item = next(it))) {
		val = item;
	}
	end = clock();
	printf("lst: accessed (iterate) %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

// 	start = clock();
// 	for (long i = 0, z = 1; i < size(lst); i++, z *= -1) {
// 		set(lst, i * z, &(t_struct){i, 'a' + i % 26});
// 	}
// 	end = clock();
// 	// foreach(lst, int_print);
// 	printf("lst: updated (random)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

// 	start = clock();
// 	for (long i = 0; i < size(lst); i++) {
// 		set(lst, i, &(t_struct){i, 'a' + i % 26});
// 	}
// 	end = clock();
// 	// foreach(lst, int_print);
// 	printf("lst: updated (linear)  %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

// 	it = iter(lst);
// 	int x = 0;
// 	start = clock();
// 	while ((val = next(it))) {
// 		*(t_struct *)val = (t_struct){x, 'a' + x % 26};
// 		x++;
// 	}
// 	end = clock();
// //	foreach(lst, int_print);
// 	printf("lst: updated (iterate) %ld items:  %fs\n\n", size(lst), TIME_DIFF(start, end));

	t_struct st;
	start = clock();
	for (long i = 0, sz = size(lst) / 2 - 10; i < sz; i++) {
		popfirst(lst, &st);
		poplast(lst, NULL);
	}
	end = clock();
	printf("lst: poped items:  %fs\n", TIME_DIFF(start, end));
	printf("size(lst): %ld\n", size(lst));

	foreach(lst, struct_print);

	delete(lst);
// */
// /**
// 	void *tst = vector(sizeof(t_struct));
// 	for (int i = 0; i <= 'z' - 'a'; i++) {
// 		t_struct tmp = {NULL, i, 'a' + i};
// 		add(tst, &tmp);
// 	}
// 	foreach(tst, struct_print);
// 	foreach(map(tst, map_struct_i), int_print);
// 	foreach(map(tst, map_struct_c), char_print);
// 	exit(0);

// 	int onstack[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
// 	it = tovector(stream(onstack, 21, sizeof(int)));
// 	foreach(reversed(reversed(view(it, 4, 60, 20))), int_print);
// 	exit(0);

	void *ints = tovector(splitted(
		"42,,1,2 2,3,4 , 000  ,4, 5,6   ,7,8  ,9,    10"
		",,,,  00123,  +456,   -1122  ,7890  ,-_-, zzz,"
		"  -666,     123456789,  ,,  NaN,    ,-10000 ,,",
		"      ,",
		sizeof(int),
		myatoi
	));

	foreach(ints, int_print);
	printf("ints = split(\"42, ..., -10000\", \" ,\", sizeof(int), myatoi)\n");
	printf("size(ints): %ld\n\n", size(ints));

// 	void *nested = vector(sizeof(t_obj *));
// 	add(nested, filter(ints, int_even));
// 	add(nested, filternot(ints, int_even));
// 	add(nested, filter(ints, int_even));
// 	foreach(take(flatmap(nested, int_mul100), 100), int_print);
// 	delete(ints);
// 	delete(nested);
// 	exit(0);

    start = clock();
	for (int i = -5; i <= 5; i++) {
		add(ints, i);
	}
	end = clock();
	foreach(drop(ints, size(ints) - 11), int_print);
	printf("add(ints, i); i <- -5..5:  %fs\n", TIME_DIFF(start, end));
	printf("size(ints): %ld\n\n", size(ints));

	foreach(filter(map(filter(ints, int_odd), int_mul1693), int_div3), int_print);
	printf("filter(map(filter(ints, int_odd), int_mul1693), int_div3): %fs\n\n", TIME_DIFF(start, end));

	foreach(filternot(ints, int_pos), int_print);
	printf("filternot(ints, int_pos)\n");
	acc = 0;
	fold(filternot(ints, int_pos), &acc, int_sum);
	printf("fold(filternot(ints, int_pos), &acc, int_sum): %ld\n\n", acc);

	foreach(takewhile(ints, int_pos), int_print);
	printf("takewhile(ints, int_pos)\n\n");

	foreach(dropwhile(drop(ints, size(ints) - 20), int_neg), int_print);
	printf("dropwhile(drop(ints, size(ints) - 20), int_neg)\n\n");

	foreach(drop(ints, 100), int_print);
	printf("drop(ints, 100)  [nothing]\n\n");

	foreach(drop(ints, size(ints) - 10), int_print);
	printf("drop(ints, size(ints) - 10)\n\n");

	it = map(map(reversed(drop(ints, size(ints) - 10)), int_mul100), int_mul100);
	patch(ints, it, 5, 10);
	foreach(take(ints, 20), int_print);
	printf("...\nints: patched items 5..15 with last 10 reversed "
			"mapped (mul100 x 2) items\n(first 20 items printed)\n\n");

	foreach(filtermap(ints, int_neg_mul1693), int_print);
	printf("filtermap(ints, int_neg_mul1693)\n\n");

	start = clock();
	for (int i = 0; i < ITEMS; i++) {
		add(ints, i);
	}
	end = clock();
	printf("add(ints, i); i <- 0..%ld:  %fs\n", ITEMS, TIME_DIFF(start, end));
	printf("size(ints): %ld\n\n", size(ints));

// 	start = clock();
// 	for (long i = 0; i < ITEMS; i++) {
// 		void *sls = view(ints, 0, 1000, 10);
// 		foreach(sls, int_print);
// 	}
// 	end = clock();
// 	printf("iter(it) x ITEMS:  %fs\n", TIME_DIFF(start, end));
// 	exit(0);

	val = reduce(ints, min_int);
	printf("reduce(ints, min_int): %d\n", *val);
	start = clock();
	val = reduce(ints, max_int);
	end = clock();
	printf("reduce(ints, max_int): %d\n"
		"average time for reduce:  %fs\n\n", *val, TIME_DIFF(start, end));
	acc = 0;
	start = clock();
	fold(ints, &acc, int_sum);
	end = clock();
	printf("fold(ints, &acc, int_sum): %ld\n"
		"average time for fold:  %fs\n\n", acc, TIME_DIFF(start, end));

	start = clock();
	acc = countif(ints, int_even);
	end = clock();
	printf("countif(ints, int_even): %ld\n"
		"time for count:  %fs\n\n", acc, TIME_DIFF(start, end));

	start = clock();
	foreach(ints, (t_f1s)int_mul100);
	end = clock();
	printf("foreach(ints, int_mul100):  %fs\n"
		"size(ints): %ld\n\n", TIME_DIFF(start, end), size(ints));

	start = clock();
	reverse(ints);
	end = clock();
// 	foreach(ints, int_print);
	printf("reverse(ints):  %fs\n\n", TIME_DIFF(start, end));

	start = clock();
	for (long i = 0, z = 1; i < size(ints); i++, z *= -1) {
		val = get(ints, i * z);
	}
	end = clock();
	printf("ints: accessed (random)  %ld items:  %fs\n", size(ints), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0; i < size(ints); i++) {
		val = get(ints, i);
	}
	end = clock();
	printf("ints: accessed (linear)  %ld items:  %fs\n", size(ints), TIME_DIFF(start, end));

	it = iter(ints);
	start = clock();
	while ((item = next(it))) {
		val = item;
	}
	end = clock();
	printf("ints: accessed (iterate) %ld items:  %fs\n\n", size(ints), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0, z = 1; i < size(ints); i++, z *= -1) {
		set(ints, i * z, &i);
	}
	end = clock();
// 	foreach(ints, int_print);
	printf("ints: updated (random)  %ld items:  %fs\n", size(ints), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0; i < size(ints); i++) {
		set(ints, i, &i);
	}
	end = clock();
// 	foreach(ints, int_print);
	printf("ints: updated (linear)  %ld items:  %fs\n", size(ints), TIME_DIFF(start, end));

	it = iter(ints);
	int x = 0;
	start = clock();
	while ((val = next(it))) {
		*val = x++;
	}
	end = clock();
// 	foreach(ints, int_print);
	printf("ints: updated (iterate) %ld items:  %fs\n\n", size(ints), TIME_DIFF(start, end));

	start = clock();
	for (long i = 0, m = (size(ints) >> 1) + 1; i < m; i++) {
		del(ints, -1L);
	}
	end = clock();
// 	foreach(ints, int_print);
	printf("del(ints, -1L) x half size; new size: %ld:  %fs\n\n", size(ints), TIME_DIFF(start, end));

	start = clock();
	it = filter(ints, int_even);
	void *flt = collect(it);
	end = clock();
// 	foreach(flt, int_print);
	printf("flt = collect(filter(ints, int_even)):  %fs\n"
		"size(flt): %ld\n\n", TIME_DIFF(start, end), size(flt));

	start = clock();
	it = sliced(flt, 1122, 94780);
	void *sl = collect(it);
	end = clock();
// 	foreach(sl, int_print);
	printf("sl = collect(sliced(flt, 1122, 94780)):  %fs\n"
		"size(sl): %ld\n\n", TIME_DIFF(start, end), size(sl));

	start = clock();
	for (long i = 0; i < 100; i++) {
		extend(flt, sl);
	}
	end = clock();
	printf("extend(flt, sl) x 100:  %fs\n", TIME_DIFF(start, end));
	printf("size(flt): %ld\n\n", size(flt));

// 	start = clock();
// 	for (long i = 1; i <= size(flt) / 4; i++) {
// 		insert(flt, -i, i);
// 	}
// 	end = clock();
// // 	foreach(flt, int_print);
// 	printf("flt: inserted to -1..-%ld:  %fs\n", size(flt) / 4, TIME_DIFF(start, end));
// 	printf("size(flt): %ld\n\n", size(flt));

	start = clock();
	val = reduce(chain(flt, ints), max_int);
	end = clock();
	printf("reduce(chain(flt, ints), max_int): %d\ntime: %f\n\n", *val, TIME_DIFF(start, end));

	start = clock();
	extend(ints, flt);
	end = clock();
	printf("extend(ints, flt):  %fs\n", TIME_DIFF(start, end));
	printf("size(ints): %ld\n\n", size(ints));

// 	printf("size(flt): %ld, size(ints): %ld\n", size(flt), size(ints));
// 	foreach(take(drop(take(ints, 1500), 30), 10), (t_f1s)int_print);
// 	foreach(take(drop(ints, 7825), 10), (t_f1s)int_print);
// 	foreach(zip(take(flt, 11), take(ints, 10)), (t_f1s)intzip_print);
// 	foreach(take(unzip(zip(drop(flt, 17), drop(ints, 100))), 50), (t_f1s)int_print);
// 	foreach(zipall(take(drop(flt, 17), 42), take(drop(ints, 100), 1000), &(int){-1}), (t_f1s)intzip_print);
// 	foreach(zip(drop(flt, 17), take(drop(ints, 100), 10)), (t_f1s)intzip_print);
// 	printf("zip(drop(flt, 17), take(drop(ints, 100), 10))\n\n");

// 	intmax_t maxsum = 0;
// 	long slicesize = size(ints) / 1000;
// 	for (long i = 0; i < size(ints); i += slicesize) {
// 		intmax_t sum = 0;
// 		it = view(ints, i, slicesize, 1);
// 		fold(it, &sum, int_sum);
// 		if (sum > maxsum)
// 			maxsum = sum;
// 	}
// 	int_print(&maxsum);
// 	printf("ints: maxsum of sliced size %ld: %ld\n\n", slicesize, maxsum);

	delete(sl);
	delete(flt);
	delete(ints);

// 	#define SORT_ITEMS 10000000L
// 	srand(0xDEAD);
// 	void *srt1 = vector(sizeof(int));
// 	for (int i = 0; i < SORT_ITEMS; i++) {
// 		add(srt1, rand() % SORT_ITEMS);
// 	}
// 	void *srt2 = clone(srt1);

// 	start = clock();
// 	sort(srt1, cmp_int);
// 	end = clock();
// // 	foreach(srt1, int_print);
// 	printf("sort(srt1, cmp_int):  %fs\n", TIME_DIFF(start, end));
// 	printf("size(srt1): %ld\n\n", size(srt1));

// 	srt2 = unwrap(srt2);
// 	start = clock();
// 	qsort(srt2, SORT_ITEMS, sizeof(int), cmp_int);
// 	end = clock();
// 	srt2 = wrap(srt2, SORT_ITEMS, sizeof(int));
// // 	foreach(srt2, int_print);
// 	printf("qsort(srt2, SORT_ITEMS, sizeof(int), cmp_int):  %fs\n", TIME_DIFF(start, end));
// 	printf("size(srt2): %ld\n\n", size(srt2));

// 	except(!equals(srt1, srt2, cmp_int), "NOT EQ");
// 	delete(srt1);
// 	delete(srt2);

// 	void *primes = split(readfile("all_primes.txt"), " \n", sizeof(int), myatoi);
// 	foreach(filter(primes, next_gt_prime), int_print);
// **/
/**
	void *str = split(
		"and  again and |AGAIN!|    ..   yoji  |"
		"146%|-- @|flamingos/zakatos |(Y)_zzzz_|"
		"GORT!\t\tKLAATU  BARADA nikto| ||!??\v|"
		"lorem ipsum dolor sit down and shut up|"
		"   ooooooo |||| no ooo plz    |    fin.",
		" |",
		sizeof(char *),
		str_cut
	);
	setattr_free(str, str_free);
	foreach(str, str_print);
	printf("str splitted\n");
	printf("size(str): %ld\n\n", size(str));

	foreach(str, str_upper);
	reverse(str);

// 	char *p1, *p2, *p3;
// 	pop(str, -3, &p1);
// 	pop(str, -1, &p2);
// 	pop(str, 2, &p3);
// 	printf("pop -3: \" %s \"\n", p1);
// 	printf("pop -1: \" %s \"\n", p2);
// 	printf("pop 2: \" %s \"\n\n", p3);
// 	free(p1); free(p2); free(p3);

	del(str, 3);
	del(str, -4L);

	emplace(str, str_dup, "~~dummy!\n");
	emplace(str, str_dup, "Frankly, my dear, I don't give a damn");
	emplace(str, str_dup, "shake your bytes");
	foreach(str, str_print);
	printf("str: emplaced 3 items\n");
	printf("size(str): %ld\n\n", size(str));

// 	char *s = ft_strdup("???update???");
// 	set(str, 2, &s);

	void *sl = collect(sliced(str, 3, 7));
	foreach(sl, str_print);
	printf("size(sl): %ld\n\n", size(sl));

	foreach(str, str_print);
	printf("str: upcase, reversed, size(changed): %ld\n\n", size(str));

	delete(sl);
	delete(str);
// **/
	return (EXIT_SUCCESS);
}

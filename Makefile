# TODO debug/release builds
NAME := libft.a
NAME_SHARED := libft.so

BUILD := build
INCLUDE := include

SRC := bigint/bi_add.c bigint/bi_clone.c bigint/bi_cmp.c bigint/bi_copy.c bigint/bi_dec.c bigint/bi_destroy.c bigint/bi_iadd.c bigint/bi_imul.c bigint/bi_inc.c bigint/bi_ipow.c bigint/bi_isnull.c bigint/bi_lsh.c bigint/bi_mul.c bigint/bi_new.c bigint/bi_normalize.c bigint/bi_pow.c bigint/bi_print.c bigint/bi_rsh.c bigint/bi_set.c bigint/bi_sub.c bigint/bi_trim.c bitset/bitset_and.c bitset/bitset_andnot.c bitset/bitset_clear.c bitset/bitset_destroy.c bitset/bitset_eq.c bitset/bitset_flip.c bitset/bitset_new.c bitset/bitset_not.c bitset/bitset_or.c bitset/bitset_put.c bitset/bitset_reset.c bitset/bitset_resize.c bitset/bitset_set.c bitset/bitset_test.c bitset/bitset_unwrap.c bitset/bitset_wrap.c bitset/bitset_xor.c collection/abstract/add.c collection/abstract/chain.c collection/abstract/chain_iter.c collection/abstract/chain_next.c collection/abstract/clear.c collection/abstract/clone.c collection/abstract/collect.c collection/abstract/concat.c collection/abstract/copy.c collection/abstract/count.c collection/abstract/countif.c collection/abstract/del.c collection/abstract/delete.c collection/abstract/distinct.c collection/abstract/distinct_iter.c collection/abstract/distinct_next.c collection/abstract/drop.c collection/abstract/dropwhile.c collection/abstract/dropwhile_iter.c collection/abstract/dropwhile_next.c collection/abstract/equals.c collection/abstract/exists.c collection/abstract/extend.c collection/abstract/filter.c collection/abstract/filtermap.c collection/abstract/filtermap_iter.c collection/abstract/filtermap_next.c collection/abstract/filter_next.c collection/abstract/filternot.c collection/abstract/filternot_next.c collection/abstract/find.c collection/abstract/findif.c collection/abstract/flatmap.c collection/abstract/flatmap_next.c collection/abstract/flatten.c collection/abstract/flatten_iter.c collection/abstract/flatten_next.c collection/abstract/fold.c collection/abstract/forall.c collection/abstract/foreach.c collection/abstract/get.c collection/abstract/getdef.c collection/abstract/indexof.c collection/abstract/indexwhere.c collection/abstract/innerab_clear.c collection/abstract/inner_clear.c collection/abstract/inner_next.c collection/abstract/isempty.c collection/abstract/iter.c collection/abstract/map.c collection/abstract/map_next.c collection/abstract/next.c collection/abstract/nth.c collection/abstract/null_iter.c collection/abstract/null_next.c collection/abstract/object.c collection/abstract/partition.c collection/abstract/patch.c collection/abstract/reduce.c collection/abstract/setattr_free.c collection/abstract/set.c collection/abstract/size.c collection/abstract/span.c collection/abstract/take.c collection/abstract/take_iter.c collection/abstract/take_next.c collection/abstract/takewhile.c collection/abstract/takewhile_next.c collection/abstract/toarray.c collection/abstract/tobuf.c collection/abstract/unzip.c collection/abstract/unzip_iter.c collection/abstract/unzip_next.c collection/abstract/util_object.c collection/abstract/util_opt.c collection/abstract/util_put.c collection/abstract/util_sequence.c collection/abstract/zipall.c collection/abstract/zipall_next.c collection/abstract/zip.c collection/abstract/zip_iter.c collection/abstract/zip_next.c collection/list/addfirst.c collection/list/first.c collection/list/last.c collection/list/list_add.c collection/list/list.c collection/list/list_clear.c collection/list/list_del.c collection/list/list_get.c collection/list/list_iter.c collection/list/list_next.c collection/list/list_set.c collection/list/popfirst.c collection/list/poplast.c collection/list/tolist.c collection/list/util_node.c collection/vector/binsearch.c collection/vector/emplace.c collection/vector/insert.c collection/vector/pop.c collection/vector/reverse.c collection/vector/reversed.c collection/vector/slice.c collection/vector/sort.c collection/vector/split.c collection/vector/splitted.c collection/vector/splitted_next.c collection/vector/stream.c collection/vector/tovector.c collection/vector/unwrap.c collection/vector/util_item.c collection/vector/util_vector.c collection/vector/vector_add.c collection/vector/vector.c collection/vector/vector_clear.c collection/vector/vector_clone.c collection/vector/vector_del.c collection/vector/vector_fold.c collection/vector/vector_foreach.c collection/vector/vector_get.c collection/vector/vector_iter.c collection/vector/vector_next.c collection/vector/vector_set.c collection/vector/view.c collection/vector/wrap.c core/amalloc.c core/except.c core/ft_atod.c core/ft_atof.c core/ft_atoi.c core/ft_bzero.c core/ft_ctype/ft_isalnum.c core/ft_ctype/ft_isalpha.c core/ft_ctype/ft_isascii.c core/ft_ctype/ft_isblank.c core/ft_ctype/ft_iscntrl.c core/ft_ctype/ft_isdigit.c core/ft_ctype/ft_isgraph.c core/ft_ctype/ft_islower.c core/ft_ctype/ft_isprint.c core/ft_ctype/ft_ispunct.c core/ft_ctype/ft_isspace.c core/ft_ctype/ft_isupper.c core/ft_ctype/ft_isxdigit.c core/ft_ctype/ft_toascii.c core/ft_ctype/ft_tolower.c core/ft_ctype/ft_toupper.c core/ft_itoa.c core/ft_memccpy.c core/ft_memchr.c core/ft_memcmp.c core/ft_memcpy.c core/ft_memdel.c core/ft_memmove.c core/ft_mempcpy.c core/ft_mempset.c core/ft_memset.c core/ft_printf/copier.c core/ft_printf/ft_dprintf.c core/ft_printf/ft_printf.c core/ft_printf/ft_sprintf.c core/ft_printf/number.c core/ft_printf/parse_fmt.c core/ft_printf/print_char.c core/ft_printf/print_float.c core/ft_printf/print_percent.c core/ft_printf/print_pointer.c core/ft_printf/print_signed.c core/ft_printf/print_string.c core/ft_printf/print_unsigned.c core/ft_printf/util_float_bufspec.c core/ft_printf/util_float.c core/ft_printf/util_fmt.c core/ft_putendl.c core/ft_putendl_fd.c core/ft_putstr.c core/ft_putstr_fd.c core/ft_qsort.c core/ft_rand.c core/ft_stpcpy.c core/ft_stpncpy.c core/ft_strcasecmp.c core/ft_strcat.c core/ft_strchr.c core/ft_strcmp.c core/ft_strcpy.c core/ft_strdup.c core/ft_strjoin.c core/ft_strlcat.c core/ft_strlcpy.c core/ft_strlen.c core/ft_strlwr.c core/ft_strncat.c core/ft_strncmp.c core/ft_strncpy.c core/ft_strndup.c core/ft_strnew.c core/ft_strnlen.c core/ft_strnstr.c core/ft_strrchr.c core/ft_strsplit.c core/ft_strstr.c core/ft_strsub.c core/ft_strtod.c core/ft_strtof.c core/ft_strtoimax.c core/ft_strtrim.c core/ft_strupr.c core/iabs.c core/ilen.c core/imax.c core/imin.c core/memdup.c core/memswap.c core/panic.c core/readfile.c core/strfind.c core/strrev.c core/strskip.c core/strtoken.c core/strtokens.c core/swap.c core/umax.c core/umin.c core/util_bytes.c core/xcalloc.c core/xmalloc.c core/xrealloc.c fifo/fifo_add.c fifo/fifo_destroy.c fifo/fifo_isempty.c fifo/fifo_iter.c fifo/fifo_new.c fifo/fifo_peek.c fifo/fifo_poll.c stack/stack_destroy.c stack/stack_isempty.c stack/stack_new.c stack/stack_peek.c stack/stack_pop.c stack/stack_push.c util/cmp/cmp_char.c util/cmp/cmp_int.c util/cmp/cmp_long.c util/cmp/cmp_str.c util/cmp/cmp_strcase.c util/cmp/cmp_uchar.c util/cmp/cmp_uint.c util/cmp/cmp_ulong.c util/cmp/max_char.c util/cmp/max_int.c util/cmp/max_long.c util/cmp/max_uchar.c util/cmp/max_uint.c util/cmp/max_ulong.c util/cmp/min_char.c util/cmp/min_int.c util/cmp/min_long.c util/cmp/min_uchar.c util/cmp/min_uint.c util/cmp/min_ulong.c util/hash/fnv1a32.c util/hash/fnv1a32s.c util/hash/fnv1a64.c util/hash/fnv1a64s.c util/hash/lowbias32.c util/hash/triple32.c workqueue/getnproc.c workqueue/util_workqueue.c workqueue/workqueue_destroy.c workqueue/workqueue_new.c workqueue/workqueue_submit.c workqueue/workqueue_wait.c
OBJ := $(SRC:%.c=$(BUILD)/%.o)
DEP := $(OBJ:%.o=%.d)

# AR := llvm-ar
AR := ar
CC := clang

MAKEFLAGS += -j

WFLAGS := -Wall -Wextra
WFLAGS += -Werror
# WFLAGS += -Wpedantic
# WFLAGS += -Wno-cast-function-type
# WFLAGS += -Wno-bad-function-cast
# OFLAGS := -O1 -g -fsanitize=address -fno-omit-frame-pointer
OFLAGS := -O2 -march=native
OFLAGS += -finline-functions
OFLAGS += -ftree-vectorize
# CFLAGS += -fpic
# OFLAGS += -flto
CFLAGS := $(WFLAGS) $(OFLAGS) -MMD -I$(INCLUDE)
# CFLAGS += -DUSEAVX2

vpath %.c src src/bigint src/bitset src/collection src/collection/abstract src/collection/list src/collection/tree src/collection/treemap src/collection/vector src/core src/core/ft_ctype src/core/ft_printf src/fifo src/stack src/util src/util/cmp src/util/hash src/workqueue

.PHONY: all clean fclean re test love debug db

$(NAME): $(OBJ)
	@printf "[$(NAME)] Linking objects...\n"
	@$(AR) rcs $@ $?
	@printf "\033[32;1m[$(NAME)] Done\033[0m\n"

-include $(DEP)
$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@printf "[$(NAME)] Building object '$@'\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_SHARED): $(OBJ)
	@$(CC) $(CFLAGS) -shared -o $@ $^

all: $(NAME)

clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_SHARED)

re: fclean
	@make all

test: all
	@test/test.sh "$(CC)" "$(CFLAGS)" "-L./ $(NAME)"

love:
	@printf 'not war\n'
	@sh bin/genmake.sh > Makefile

debug:
	@printf 'nope\n'

db:
	@compiledb make

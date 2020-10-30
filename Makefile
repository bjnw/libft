# TODO debug/release builds
NAME := libft.a
NAME_SHARED := libft.so

BUILD := build
INCLUDE := include

SRC := asm/asm_bsf.c asm/asm_bsr.c asm/asm_bt.c asm/asm_btc.c asm/asm_btr.c asm/asm_bts.c asm/asm_fsqrt.c bigint/bi_add.c bigint/bi_clone.c bigint/bi_cmp.c bigint/bi_copy.c bigint/bi_dec.c bigint/bi_delete.c bigint/bi_iadd.c bigint/bi_imul.c bigint/bi_inc.c bigint/bi_ipow.c bigint/bi_isnull.c bigint/bi_lsh.c bigint/bi_mul.c bigint/bi_new.c bigint/bi_normalize.c bigint/bi_pow.c bigint/bi_print.c bigint/bi_rsh.c bigint/bi_set.c bigint/bi_sub.c bigint/bi_trim.c bitset/bs_delete.c bitset/bs_flip.c bitset/bs_get.c bitset/bs_new.c bitset/bs_set.c collection/abstractobj/clear.c collection/abstractobj/clone.c collection/abstractobj/foreach.c collection/abstractobj/extend.c collection/abstractobj/copy.c collection/abstractobj/iter.c collection/abstractobj/next.c collection/abstractobj/set.c collection/abstractobj/collect.c collection/abstractobj/toarray.c collection/abstractobj/setattr_dtor.c collection/abstractobj/setattr_fallback.c collection/abstractobj/size.c collection/abstractobj/get.c collection/abstractobj/add.c collection/abstractobj/del.c collection/abstractobj/reduce_r.c collection/abstractobj/foreach_r.c collection/abstractobj/fold_r.c collection/abstractobj/fold.c collection/abstractobj/delete.c collection/abstractobj/reduce.c collection/abstractobj/exists.c collection/abstractobj/forall.c collection/abstractobj/isempty.c collection/abstractobj/equals.c collection/abstractobj/concat.c collection/abstractobj/nth.c collection/abstractobj/util.c collection/abstractobj/filter.c collection/abstractobj/filter_r.c collection/abstractobj/filtermap.c collection/abstractobj/filtermap_r.c collection/abstractobj/map_r.c collection/abstractobj/map.c collection/abstractobj/map_next.c collection/abstractobj/filter_next.c collection/abstractobj/filtermap_next.c collection/abstractobj/map_next_r.c collection/abstractobj/filter_next_r.c collection/abstractobj/filtermap_next_r.c collection/abstractseq/util.c collection/abstractseq/count.c collection/abstractseq/count_r.c collection/abstractseq/find.c collection/abstractseq/find_r.c collection/abstractseq/indexof.c collection/abstractseq/indexof_r.c collection/list/list_add.c collection/list/list_set.c collection/list/list_clone.c collection/list/poplast.c collection/list/list_init.c collection/list/list_del.c collection/list/list_get.c collection/list/last.c collection/list/first.c collection/list/list.c collection/list/tolist.c collection/list/addfirst.c collection/list/list_clear.c collection/list/list_next.c collection/list/list_iter.c collection/list/popfirst.c collection/list/list_copy.c collection/list/util_node.c collection/vector/util_vector.c collection/vector/split.c collection/vector/takewhile.c collection/vector/drop.c collection/vector/dropwhile.c collection/vector/insert.c collection/vector/patch.c collection/vector/slice.c collection/vector/take.c collection/vector/unwrap.c collection/vector/vector_add.c collection/vector/vector_clone.c collection/vector/vector_copy.c collection/vector/vector_del.c collection/vector/vector_get.c collection/vector/vector_set.c collection/vector/vector_init.c collection/vector/vector.c collection/vector/vector_iter.c collection/vector/reversed.c collection/vector/vector_next.c collection/vector/view.c collection/vector/wrap.c collection/vector/tovector.c collection/vector/bfind.c collection/vector/sort.c collection/vector/reverse.c collection/vector/vector_clear.c collection/vector/util_item.c collection/vector/pop.c collection/vector/emplace.c core/ft_abs.c core/ft_atoi.c core/ft_atou.c core/ft_bzero.c core/ft_foreach.c core/ft_imax.c core/ft_imin.c core/ft_intlen.c core/ft_isalnum.c core/ft_isalpha.c core/ft_isascii.c core/ft_isblank.c core/ft_iscntrl.c core/ft_isdigit.c core/ft_isgraph.c core/ft_islower.c core/ft_isprint.c core/ft_ispunct.c core/ft_isspace.c core/ft_isupper.c core/ft_isxdigit.c core/ft_itoa.c core/ft_map.c core/ft_memccpy.c core/ft_memchr.c core/ft_memcmp.c core/ft_memcpy.c core/ft_memdel.c core/ft_memdup.c core/ft_memmove.c core/ft_mempcpy.c core/ft_mempset.c core/ft_memset.c core/ft_printf/copier.c core/ft_printf/ft_dprintf.c core/ft_printf/ft_printf.c core/ft_printf/ft_sprintf.c core/ft_printf/ft_vsprintf.c core/ft_printf/number.c core/ft_printf/parse_fmt.c core/ft_printf/print_char.c core/ft_printf/print_float.c core/ft_printf/print_percent.c core/ft_printf/print_pointer.c core/ft_printf/print_signed.c core/ft_printf/print_string.c core/ft_printf/print_unsigned.c core/ft_printf/util_float.c core/ft_printf/util_float_bufspec.c core/ft_printf/util_fmt.c core/ft_putendl.c core/ft_putendl_fd.c core/ft_putstr.c core/ft_putstr_fd.c core/ft_qsort.c core/ft_rand.c core/ft_stpcpy.c core/ft_stpncpy.c core/ft_strcasecmp.c core/ft_strcat.c core/ft_strchr.c core/ft_strcmp.c core/ft_strcpy.c core/ft_strdup.c core/ft_strelems.c core/ft_strjmp.c core/ft_strjoin.c core/ft_strlcat.c core/ft_strlcpy.c core/ft_strlen.c core/ft_strlwr.c core/ft_strncat.c core/ft_strncmp.c core/ft_strncpy.c core/ft_strndup.c core/ft_strnew.c core/ft_strnlen.c core/ft_strnstr.c core/ft_strrchr.c core/ft_strrev.c core/ft_strsep.c core/ft_strsplit.c core/ft_strstr.c core/ft_strsub.c core/ft_strtrim.c core/ft_strupr.c core/ft_swap.c core/ft_toascii.c core/ft_tolower.c core/ft_toupper.c core/ft_umax.c core/ft_umin.c core/ft_utoa.c core/malloca.c core/mw_testchar.c core/mw_testnull.c core/xcalloc.c core/xmalloc.c core/xrealloc.c core/except.c core/panic.c hash/fnv1a32.c hash/fnv1a32s.c hash/fnv1a64.c hash/fnv1a64s.c hash/lowbias32.c hash/triple32.c slab/sl_finalize.c slab/sl_free.c slab/sl_malloc.c slab/util.c task/task.c util/cmp_int32.c util/cmp_int32p.c util/cmp_int64.c util/cmp_int64p.c util/cmp_int8.c util/cmp_int8p.c util/cmp_uint32.c util/cmp_uint32p.c util/cmp_uint64.c util/cmp_uint64p.c util/cmp_uint8.c util/cmp_uint8p.c util/max_int32p.c util/max_int64p.c util/max_int8p.c util/max_uint32p.c util/max_uint64p.c util/max_uint8p.c util/min_int32p.c util/min_int64p.c util/min_int8p.c util/min_uint32p.c util/min_uint64p.c util/min_uint8p.c 
OBJ := $(SRC:%.c=$(BUILD)/%.o)
DEP := $(OBJ:%.o=%.d)

# AR := llvm-ar
# RANLIB := llvm-ranlib
AR := ar
RANLIB := ranlib

CC := clang
WFLAGS := -Wall -Wextra
# WFLAGS += -Wpedantic
# WFLAGS += -Werror
OFLAGS := -O2 -march=native
OFLAGS += -ftree-vectorize
# OFLAGS += -flto=thin
CFLAGS := $(WFLAGS) $(OFLAGS) -MMD -I$(INCLUDE)
# CFLAGS += -fPIC

vpath %.c src src/asm src/bigint src/bitset src/collection src/collection/abstractobj src/collection/abstractseq src/collection/hashmap src/collection/hashset src/collection/list src/collection/tree src/collection/vector src/core src/core/ft_printf src/hash src/slab src/task src/util 

.PHONY: all clean fclean re test love debug db

$(NAME): $(OBJ)
	@printf "[$(NAME)] Linking objects...\n"
	@$(AR) rcs $@ $?
	@$(RANLIB) $@
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

re: fclean all

test: all
	@test/test.sh "$(CC)" "$(CFLAGS)" "-L./ $(NAME)"

love:
	@printf 'not war\n'
	@sh bin/genmake.sh > Makefile

debug:
	@printf 'nope\n'

db:
	@compiledb make

# TODO debug/release builds
NAME := libft.a
NAME_SHARED := libft.so

BUILD := build
INCLUDE := include

SRC := asm/asm_fsqrt.c asm/asm_bts.c asm/asm_btr.c asm/asm_bsr.c asm/asm_bsf.c asm/asm_btc.c asm/asm_bt.c bigint/bi_add.c bigint/bi_clone.c bigint/bi_cmp.c bigint/bi_copy.c bigint/bi_dec.c bigint/bi_iadd.c bigint/bi_imul.c bigint/bi_inc.c bigint/bi_ipow.c bigint/bi_isnull.c bigint/bi_lsh.c bigint/bi_mul.c bigint/bi_normalize.c bigint/bi_pow.c bigint/bi_print.c bigint/bi_rsh.c bigint/bi_new.c bigint/bi_delete.c bigint/bi_set.c bigint/bi_sub.c bigint/bi_trim.c bitset/bs_delete.c bitset/bs_new.c bitset/bs_flip.c bitset/bs_set.c bitset/bs_get.c collection/sequence/locate_r.c collection/sequence/count_r.c collection/sequence/locate.c collection/sequence/search.c collection/sequence/count.c collection/sequence/search_r.c collection/generic/add.c collection/generic/toarray.c collection/generic/size.c collection/generic/set.c collection/generic/next.c collection/generic/map_r.c collection/generic/map.c collection/generic/get.c collection/generic/foreach_r.c collection/generic/foreach.c collection/generic/empty.c collection/generic/delete.c collection/generic/del.c collection/generic/copy.c collection/generic/clone.c collection/generic/extend.c collection/generic/clear.c collection/generic/iter.c collection/generic/filter.c collection/generic/filter_r.c collection/generic/fold.c collection/generic/fold_r.c collection/generic/collect.c collection/generic/concat.c collection/deque/last.c collection/deque/deque.c collection/deque/todeque.c collection/deque/poplast.c collection/deque/popfirst.c collection/deque/first.c collection/deque/deque_set.c collection/deque/deque_next.c collection/deque/deque_iter.c collection/deque/deque_get.c collection/deque/deque_del.c collection/deque/deque_copy.c collection/deque/deque_clone.c collection/deque/deque_clear.c collection/deque/deque_init.c collection/deque/util_node.c collection/deque/addfirst.c collection/deque/deque_add.c collection/deque/util_item.c collection/list/drop.c collection/list/emplace.c collection/list/insert.c collection/list/list_add.c collection/list/list_clear.c collection/list/list_clone.c collection/list/list_copy.c collection/list/list_del.c collection/list/list_get.c collection/list/list_init.c collection/list/list_set.c collection/list/parse.c collection/list/pop.c collection/list/reverse.c collection/list/reversed.c collection/list/slice.c collection/list/tolist.c collection/list/util_item.c collection/list/util_list.c collection/list/stepby.c collection/list/sort.c collection/list/wrap.c collection/list/list.c collection/list/list_iter.c collection/list/list_next.c collection/list/unwrap.c collection/list/take.c collection/list/dropwhile.c collection/list/takewhile.c core/ft_abs.c core/ft_atoi.c core/ft_atou.c core/ft_bzero.c core/ft_hash.c core/ft_imax.c core/ft_imin.c core/ft_intlen.c core/ft_isalnum.c core/ft_isalpha.c core/ft_isascii.c core/ft_isblank.c core/ft_iscntrl.c core/ft_isdigit.c core/ft_isgraph.c core/ft_islower.c core/ft_isprint.c core/ft_ispunct.c core/ft_isspace.c core/ft_isupper.c core/ft_isxdigit.c core/ft_itoa.c core/ft_memccpy.c core/ft_memchr.c core/ft_memcmp.c core/ft_memcpy.c core/ft_memdel.c core/ft_memdelpv.c core/ft_memdup.c core/ft_memmove.c core/ft_mempset.c core/ft_memset.c core/ft_memswap.c core/ft_putendl.c core/ft_putendl_fd.c core/ft_putstr.c core/ft_putstr_fd.c core/ft_qsort.c core/ft_rand.c core/ft_stpcpy.c core/ft_stpncpy.c core/ft_strcasecmp.c core/ft_strcat.c core/ft_strchr.c core/ft_strcmp.c core/ft_strcpy.c core/ft_strdup.c core/ft_strelems.c core/ft_strjmp.c core/ft_strjoin.c core/ft_strlcat.c core/ft_strlcpy.c core/ft_strlen.c core/ft_strlwr.c core/ft_strncat.c core/ft_strncmp.c core/ft_strncpy.c core/ft_strndup.c core/ft_strnew.c core/ft_strnlen.c core/ft_strnstr.c core/ft_strrchr.c core/ft_strrev.c core/ft_strsep.c core/ft_strsplit.c core/ft_strstr.c core/ft_strsub.c core/ft_strtrim.c core/ft_strupr.c core/ft_toascii.c core/ft_tolower.c core/ft_toupper.c core/ft_umax.c core/ft_umin.c core/ft_utoa.c core/mw_pack.c core/mw_testchar.c core/mw_testnull.c core/panic.c core/xcalloc.c core/xrealloc.c core/xmalloc.c core/ft_foreach.c core/ft_map.c core/gc_finalize.c core/gc_sweep.c core/gc_malloc.c core/ft_mempcpy.c slab/sl_finalize.c slab/sl_malloc.c slab/util.c slab/sl_free.c 
OBJ := $(SRC:%.c=$(BUILD)/%.o)
DEP := $(OBJ:%.o=%.d)

AR := llvm-ar
RANLIB := llvm-ranlib

CC := clang
WFLAGS := -Wall -Wextra
# WFLAGS += -Wpedantic
# WFLAGS += -Werror
OFLAGS := -O2 -march=native
OFLAGS += -ftree-vectorize
OFLAGS += -flto=thin
CFLAGS := $(WFLAGS) $(OFLAGS) -fPIC -MMD -I./$(INCLUDE)

vpath %.c src src/bigint src/bitset src/core src/collection src/collection/sequence src/collection/generic src/collection/hashset src/collection/deque src/collection/tree src/collection/hashmap src/collection/list src/slab src/asm 

.PHONY: all clean fclean re test love debug

$(NAME): $(OBJ)
	@echo "Linking static library '$@'..."
	@$(AR) rcs $@ $?
	@$(RANLIB) $@

-include $(DEP)
$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@echo "Building object '$@'"
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
	@echo 'not war'
	@sh util/genmake.sh > Makefile

debug:
	@echo 'nope'

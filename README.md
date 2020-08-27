[![License](https://img.shields.io/badge/License-WTFPL-gray.svg)](https://github.com/bjnw/libft/blob/master/LICENSE)

# libft
![Achievement unlocked!](https://user-images.githubusercontent.com/8770733/78032772-30c47680-736e-11ea-87a3-91d71b92485e.png)

## Ne plus ultra
#### Collections (iterators included)
Superclass,  provides ``map()``, ``filter()``, ``reduce()``, and some other methods (with its closure-like variants) for all objects, derived from this class
[include/abstractobj.h](https://github.com/bjnw/libft/blob/master/include/collection/abstractobj.h)
[src/collection/abstract](https://github.com/bjnw/libft/blob/master/src/collection/abstract)

Example: ``abstractobj`` → ``sequenceobj`` → ``vector``
``Vector`` is a general-purpose data structure. It provides random access and updates in effectively constant time, as well as fast append, and automagically resizes. ``Vector`` extends ``abstractobj`` with some useful methods (almost zero-cost) e.g. ``reversed()``, ``take()``/``drop()``, ``slice()``, etc.

[include/vector.h](https://github.com/bjnw/libft/blob/master/include/collection/vector.h)

[src/collection/vector](https://github.com/bjnw/libft/blob/master/src/collection/vector)

#### Baby’s first garbage collector
This implementation of semi-automatic GC uses information about call stack growing
(mnemonic is “<ins>m</ins>emory <ins>alloc</ins>ate <ins>a</ins>utomatic”)

[src/core/malloca.c](https://github.com/bjnw/libft/blob/master/src/core/malloca.c)

[src/core/malloca.h](https://github.com/bjnw/libft/blob/master/src/core/malloca.h)

## Programming pearls and best practices
```c
void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
```
## Épilogue
feel free to `free()`

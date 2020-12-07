[![License](https://img.shields.io/badge/License-WTFPL-gray.svg)](https://github.com/bjnw/libft/blob/master/LICENSE)

# libft
![Achievement unlocked!](https://user-images.githubusercontent.com/8770733/91582880-1d3b2d00-e959-11ea-9b12-427b1fad79da.png)

## Ne plus ultra
### Collections (iterators included)
``Abstractobj`` is a superclass, provides common high-order functions and internal iterators (e.g. ``map()``, ``filter()``, ``reduce()``, ``zip()``, ``take()``, ``foreach()``, ``iter()``, ``next()``…) for all objects, derived from this class.

[include/abstractobj.h](https://github.com/bjnw/libft/blob/master/include/collection/abstractobj.h)

[src/collection/abstractobj](https://github.com/bjnw/libft/blob/master/src/collection/abstractobj)

``Vector`` is a general-purpose cache-friendly data structure. It provides random access and updates in effectively constant time, as well as fast append, and automagically resize. ``Vector`` extends ``abstractobj`` with [``abstractseq``](https://github.com/bjnw/libft/blob/master/include/collection/abstractseq.h) and provides some utile methods and iterators (e.g ``slice()``, ``reversed()``, ``find()``, ``patch()``).

[include/collection/vector.h](https://github.com/bjnw/libft/blob/master/include/collection/vector.h)

[src/collection/vector](https://github.com/bjnw/libft/blob/master/src/collection/vector)

### Thread pool
Thread pool provides a convenient way for dispatching asynchronous tasks. Group of pre-instantiated, idle threads which stand ready to work preferred over instantiating new threads for each task when there are numerous quick tasks rather than a few long ones. This prevents having to incur the overhead of creating a thread many times.

[include/pthreadpool.h](https://github.com/bjnw/libft/blob/master/include/pthreadpool.h)

[src/pthreadpool](https://github.com/bjnw/libft/blob/master/src/pthreadpool)

### Baby’s first garbage collector
This implementation of semi-automatic GC uses information about call stack behavior.

[src/core/malloca.c](https://github.com/bjnw/libft/blob/master/src/core/malloca.c)

### BigInt
Unpretentious big integer math library.

[include/bigint.h](https://github.com/bjnw/libft/blob/master/include/bigint.h)

[src/bigint](https://github.com/bjnw/libft/blob/master/src/bigint)

## Épilogue
feel free to `free()`

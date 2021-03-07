[![License](https://img.shields.io/badge/License-WTFPL-gray.svg)](https://github.com/bjnw/libft/blob/master/LICENSE)

# libft
![Achievement unlocked!](https://user-images.githubusercontent.com/8770733/91582880-1d3b2d00-e959-11ea-9b12-427b1fad79da.png)

## Ne plus ultra
### Collections (iterators included)
``Abstract`` is a base class for iterable collections, that provides common high-order functions and internal iterators (e.g. ``map()``, ``filter()``, ``reduce()``, ``flatten()``, ``zip()``, ``take()``, ``foreach()``, ``iter()``, ``next()``…) for all objects, derived from this class.

[include/abstract.h](https://github.com/bjnw/libft/blob/master/include/collection/abstract.h)

[src/collection/abstract](https://github.com/bjnw/libft/blob/master/src/collection/abstract)

``Vector`` is a general-purpose cache-friendly data structure. It provides quick random access and updates in effectively constant time, as well as fast append, and automagically resize. ``Vector`` provides some utile methods and iterators (e.g ``stream()``, ``slice()``, ``reversed()``, ``find()``, ``binsearch()``, ``patch()``, ``sort()``).

[include/collection/vector.h](https://github.com/bjnw/libft/blob/master/include/collection/vector.h)

[src/collection/vector](https://github.com/bjnw/libft/blob/master/src/collection/vector)

### Workqueue
Workqueue is a convenient way for dispatching queue of asynchronous tasks. Group of pre-instantiated, idle threads, which stand ready to work, prevents having to incur the overhead of creating a thread many times for each task.

[include/workqueue.h](https://github.com/bjnw/libft/blob/master/include/workqueue.h)

[src/workqueue](https://github.com/bjnw/libft/blob/master/src/workqueue)

### Baby’s first garbage collector
This implementation of semi-automatic GC uses information about call stack behavior.

[src/core/amalloc.c](https://github.com/bjnw/libft/blob/master/src/core/amalloc.c)

### BigInt
Unpretentious big integer math library.

[include/bigint.h](https://github.com/bjnw/libft/blob/master/include/bigint.h)

[src/bigint](https://github.com/bjnw/libft/blob/master/src/bigint)

## Épilogue
feel free to `free()`

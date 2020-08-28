[![License](https://img.shields.io/badge/License-WTFPL-gray.svg)](https://github.com/bjnw/libft/blob/master/LICENSE)

# libft
![Achievement unlocked!](https://user-images.githubusercontent.com/8770733/91582880-1d3b2d00-e959-11ea-9b12-427b1fad79da.png)

## Ne plus ultra
### Collections (iterators included)
``Abstractobj`` is a superclass,  provides common methods and iterators (e.g. ``map()``, ``filter()``, ``reduce()``, ``iter()``, ``next()``) for all objects, derived from this class

[include/abstractobj.h](https://github.com/bjnw/libft/blob/master/include/collection/abstractobj.h)

[src/collection/abstract](https://github.com/bjnw/libft/blob/master/src/collection/abstract)

``Vector`` is a general-purpose data structure. It provides random access and updates in effectively constant time, as well as fast append, and automagically resize. ``Vector`` extends ``abstractobj`` with ``sequenceobj`` and provides some utile methods and iterators

[include/vector.h](https://github.com/bjnw/libft/blob/master/include/collection/vector.h)

[src/collection/vector](https://github.com/bjnw/libft/blob/master/src/collection/vector)

### Baby’s first garbage collector
This implementation of semi-automatic GC uses information about call stack behavior

[src/core/malloca.c](https://github.com/bjnw/libft/blob/master/src/core/malloca.c)

[src/core/malloca.h](https://github.com/bjnw/libft/blob/master/src/core/malloca.h)

## Épilogue
feel free to `free()`

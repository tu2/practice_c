# C idioms

from **K.N. King - C Programming A Modern Approach second edition 2008**

## Searching for the end of a string

Version 1

```c
size_t strlen(const  char *s)
{
    size_t n = 0;

    while (*s++)
        n++;

    return n;
}
```
Version 2

```c
size_t strlen(const char *s)
{
    const char *p = s;
    while (*s)
        s++;

    return s - p;
}
```

**IDIOMS**

```c
while (*s)
    s++;
```

```c
while (*s++)
    ;
```

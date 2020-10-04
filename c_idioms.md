# C idioms

from **K.N. King - C Programming A Modern Approach** second edition 2008

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
Version 2 - faster, don't need a counter inside the loop

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

## Copying a string

```c
char *strcat (char *s1, const char *s2)
{
    char *p = s1;

    while (*p)
        p++;
    while (*p++ = *s2++)
        ;
    return s1;
}
```
**IDIOM**
```c
while (*s)
    s++
```
```c
while (*s++)
    ;
```

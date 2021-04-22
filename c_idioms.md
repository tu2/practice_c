# C Idioms

from **K.N. King - C Programming A Modern Approach** second edition 2008

## Reading strings character by character

```c
int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}

```

## Searching for the end of a string

*Version 1 could be slow*

```c
size_t strlen(const  char *s)
{
    size_t n = 0;

    while (*s++)
        n++;

    return n;
}
```
*Version 2 is faster, there's no need for a counter inside the loop*

```c
size_t strlen(const char *s)
{
    const char *p = s;
    while (*s)
        s++;

    return s - p;
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

## Copying a string

```c
char *strcat (char *s1, const char *s2)
{
    char *p = s1;

    while (*p)
        p++;
    while ((*p++ = *s2++) != 0)
        ;
    return s1;
}
```
**IDIOM**
```c
while (*p++ = *s2++)
    ;
```

## Inverse Square Root
**A Fast Quake III Algorithm** 
[Source](https://www.youtube.com/watch?v=p8u_k2LIZyo)


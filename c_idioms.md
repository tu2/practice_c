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

*Version 1 is slow when used on a large string*

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
OR

```c
while (*s++)
    ;
```

## Concatenating two strings

```c
/* copy the content of s2 to the end of s1 */

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
while ((*p++ = *s2++) != 0)
    ;
```
or

```c
while ((*p++ = *s2++))
    ;
```

## Fast Inverse Square Root
**A Quake III Algorithm** 

[History](https://medium.com/hard-mode/the-legendary-fast-inverse-square-root-e51fee3b49d9)

[Explanation](https://www.youtube.com/watch?v=p8u_k2LIZyo)


```c
float Q_rsqrt( float number )
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;
  
  x2 =number * 0.5F;
  y = number;
  i = * ( long * ) &y;      //evel floating point bit level
  i = 0x5f3759df - ( i >> 1);              //what the fuck?
  y = * ( float * ) &i;
  y = y * ( threehalfs - ( x2 * y * y ) ); //1st iteration
//  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration,
                                              // this can be removed

  return y;
}
```
Better use today:

```c
#include <math.h>

float y = 1/sqrt(x);
```

/*
 *  NOTES ON STRINGS with some examples (SOURCE: K.N. King C Programming a Modern Approach 2nd ed, man pages and some online resources)
 *   #string.h -> create, store, copy, concatenate, length
 *   
 *   - strlen -- find length of string
 *   size_t strlen(const char *string);
 *   
 *   - strcpy -- copy strings from 'src' to 'dest' including '\0'
 *   char *strcpy(char *dest, const char *src);
 *   
 *   - strncpy -- copy the 'n' byts of 'src' to 'dst', if there is no NULL character among the first n character of src, the string placed in dest will not be NULL-terminated 
 *   char *strncpy(char *dest, const char *src, size_t n);
 *   
 *   - strcat -- the strcat() function appends the 'src' string to the 'dest' string, overwriting the terminating null byte ('\0') at the end of dest, and then adds a terminating null byte.  The strings may not overlap, and the dest string must have enough space for the result.  If dest is not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure programs.
 *   char *strcat(char *dest, const char *src);
 * 
 *   - strncat -- appends 'n' characters from 'src' to 'dest' and adds '\0'
 *   char *strncat(char *dest, const char *src, size_t n);
 *   
 *   Not standard POSIX
 *   - strlcpy - (BSD) - https://www.sudo.ws/todd/papers/strlcpy.html
 *   take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0 ). A byte for the NUL should be included in size and src must be NUL-terminated
 *   size_t strlcpy(char *dest, const char *src, size_t size);
 *  
 *  MORE: strcpy_s, need some examples
 *   
 *  Practice these functions
 *
 *  TODO: Parse a string: scanf, fscanf, sscanf, scanf_s, fscanf_s, ssscanf_s
 */

#include <stdio.h>
#include <string.h>

#define N 100

int my_length(const char *string);

int read_line(char s[], int n);

int count_space(const char *s);

int main(void)
{
        
    char s1[N];
    char s2[N];
    char s3[N*2];

    char intro[] = "This program reads a line of chars from stdinput\ncalculates the length of the string and prints it on the stdout.\nPlease enter a line of characters:";
    char intro2[] = "Enter a new line";
    char line[] = "-------- *** --------";

    /* Reading 1st line of characters*/
    puts(line);

    puts(intro);

    read_line(s1, sizeof(s1)-1);

    printf("\nString 1\nhas %d chars %d spaces.\n", my_length(s1), count_space(s1));

    /* 
     * Copy s1 into s3 using function from standard library
     * strcpy(s3, s1) - function UNSAFE, it doesn't check if there is enough space in s3
     * strncpy(s3, s1, sizeof(s3)-1) is better 
     * strncpy doesn't add null character
     */
    strncpy(s3, s1, sizeof(s3)-1);

    s3[sizeof(s3)-1] = '\0';

    puts(intro2);  

    fgets(s2, sizeof(s2), stdin);

    /* 
    *  Concatenate s2 to s3
    *  strcat(s3, s2) - function UNSAFE, it doesn't check if there is enough space in s3
    *  strncat(s3, s2, sizeof(s3)-strlen(s3)-1)
    */
    strncat(s3, s2, sizeof(s3)-strlen(s3)-1);

    printf("\nString 2\nhas %d chars %d spaces.\n", my_length(s2), count_space(s2));
    
    printf("\nStrings combined:\n%s\nThere are %ld chars %d spaces.\n", s3, strlen(s3), count_space(s3));

    puts(line);
        
    /* End print */
    return 0;

}

/* Read characters in a line */
int read_line(char s[], int n)
{

    int ch, i = 0;
    
    while ((ch = getchar()) != '\n')
        
        if ( i < n)
            s[i++] = ch;
    
    s[i] = '\0';
    
    return i;

}

/* Calculate the lenght of the string */
int my_length( const char *string )
{

    size_t n = 0;

    while(*string++)
        n++;
    
    return n;

}

/* Count space */
int count_space(const char *s)
{

    int count = 0;

    while(*s++)
        if(*s == ' ')
            count++;
    
    return count;

}

/* example count spaces using an array

int count_space(const char s[])
{
        int count = 0, i;
        for (i = 0, s[i] != '\0'; i++)
                if (s[i] == ' ')
                        count++;
        return count;
}

*/ 


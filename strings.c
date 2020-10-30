/* 
 * Strings: (from chap 13 K.N. King C programming a modern approach 2nd ed) 
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
 *   - strcat --
 *   char *strcat(char *dest, const char *src);
 * 
 *   - strncat --
 *   char *strncat(char *dest, const char *src, size_t n);
 *   
 *   Not standard POSIX
 *   - strlcpy -- BSD
 *   size_t strlcpy(char *dest, const char *src, size_t size);
 *
 *  Practice these functions
 */

#include <stdio.h>
#include <string.h>

#define N 100

int my_length( const char *string);

int read_line(char s[], int n);

int count_space(const char *s);

int main (void)
{
        char s1[N];
        char s2[N];
        char s3[N*2];

        char intro[] = "This program reads a line of chars from stdinput\ncalculates the length of the string and prints it on the stdout.\nPlease enter less the 100 characters:";
        char intro2[] = "Enter a new string";
        char line[] = "-------- *** --------";

        /* Start print */
        
        puts(line);

        puts(intro);

        read_line(s1, sizeof(s1)-1);

        printf("\nString 1\nhas %d chars %d spaces.\n", my_length(s1), count_space(s1));

        /* 
         * Copy s1 into s3
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


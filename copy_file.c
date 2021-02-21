/* 
* Copy one file (source) to another file (dest) 
* Example of open/write files
*/

#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
    FILE *source, *dest;
    char ch;

    if (argc != 3){
        printf("Usage: copy_file <source> <destination>\n");
        exit(1);
    }

    /* open source file */
    if (( source = fopen(argv[1], "rb")) == NULL){
        printf("Can't open source file!\n");
        exit(1);
    }

    /* open destination file */
    if (( dest = fopen(argv[2], "wb")) == NULL){
        printf("Can't open destination file!\n");
        exit(1);
    }

    /* copy form source to destination*/

    while (!feof(source)){
        ch = fgetc(source);
        if (ferror(source)){
            printf("Error reading source file!\n");
            exit(1);
        }

        if (!feof(source)) 
            fputc(ch, dest);
        if (ferror(dest)){
            printf("Error writing destination file!\n");
            exit(1);
        }
    }

    
    if (fclose(source) == EOF){
        printf("Error closing source file!\n");
        exit(1);
    }

    if (fclose(dest) == EOF){
        printf("Error closing destination file!\n");
        exit(1);
    }


    return 0;
}

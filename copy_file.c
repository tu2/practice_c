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
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* open source file */
    if (( source = fopen(argv[1], "rb")) == NULL){
        fprintf(stderr, "Can't open source file!\n");
        exit(EXIT_FAILURE);
    }

    /* open destination file */
    if (( dest = fopen(argv[2], "wb")) == NULL){
        fprintf(stderr, "Can't open destination file!\n");
        exit(EXIT_FAILURE);
    }

    /* copy form source to destination*/

    while (!feof(source)){
        ch = fgetc(source);
        if (ferror(source)){
            fprintf(stderr, "Error reading source file!\n");
            exit(EXIT_FAILURE);
        }

        if (!feof(source)) 
            fputc(ch, dest);
        if (ferror(dest)){
            fprintf(stderr, "Error writing destination file!\n");
            exit(EXIT_FAILURE);
        }
    }
    
    /* close files */
    
    if (fclose(source) == EOF){
        fprintf(stderr, "Error closing source file!\n");
        exit(EXIT_FAILURE);
    }

    if (fclose(dest) == EOF){
        fprintf(stderr, "Error closing destination file!\n");
        exit(EXIT_FAILURE);
    }


    return (EXIT_SUCCESS);
}

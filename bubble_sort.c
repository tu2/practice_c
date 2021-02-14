/* 
 *  A very simple implementation of a bubble-sort algorithm in c. 
 */

#include <stdio.h>
#define SIZE 5

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s", str);

    for (i = 0; i < how_many; i++)
        printf("%d\t", data[i]);
}

void bubble(int data[], int how_many)
{
    for (int i = 0; i < how_many; i++){
        for(int j = how_many - 1; j > i; j--)
            if(data[j-1] > data[j])
                swap(&data[j-1], &data[j]);
    }
}

int main(void)
{
    /* Test with a fix size unsorted list */
    int my_list[SIZE] = {78, 67, -92, 83, 88};
    
    printf("\n");
    print_array(SIZE, my_list, "Unsorted List\n");

    bubble(my_list, SIZE);
    printf("\n"); 
    
    print_array(SIZE, my_list, "Sorted list:\n");
    printf("\n");

    return 0;

}


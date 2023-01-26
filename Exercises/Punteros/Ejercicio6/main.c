#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME
#define SIZE 4

struct picture_info{
int date_time;
char name[SIZE_NAME];
}pictures[SIZE];


int main()
{
    struct picture_info *picture_pointers[SIZE];

    for(int i = 0; i < SIZE; i++){
        picture_pointers[i] = &pictures[i];
        printf("%d\n", &picture_pointers);
    }


    return 0;
}

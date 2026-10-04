#include <stdio.h>
#include <stdlib.h> // Required for malloc, calloc, realloc, and free

int main() {
    // 1. MALLOC: Allocate space for a single integer
    int *a = (int *)malloc(sizeof(int)); // a stores address of memory allocated

    if (a == NULL) // if memory not allocated NULL is stored in a
    {
        printf("Malloc failed\n");
        return 1;
    }

    *a = 77;

    // 2. CALLOC: Allocate an array of 3 integers (initialized to 0)
    int array_size = 3;
    int *my_array = (int *)calloc(array_size, sizeof(int));

    if (my_array == NULL) {
        printf("Calloc failed\n");
        return 1;
    }

    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;

    // 3. REALLOC: Expand the calloc array size from 3 to 4 elements
    int new_size = 4;
    int *temp = (int *)realloc(my_array, new_size * sizeof(int));

    if (temp == NULL) {
        printf("Realloc failed\n");
        return 1;
    }

    my_array = temp;
    my_array[3] = 40;

    printf("a value: %d\n", *a);

    for (int i = 0; i < new_size; i++) {
        printf("my_array[%d] = %d\n", i, my_array[i]);
    }

    // 4. FREE: Deallocate the memory blocks
    free(a);
    free(my_array);

    a = NULL;
    my_array = NULL;

    return 0;
}

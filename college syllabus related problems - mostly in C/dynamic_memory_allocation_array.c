
#include <stdio.h>
#include <stdlib.h>

void printArray(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = 2;
    int cols = 3;

    // Dynamically allocate memory for the 2D array
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    /*
     //alternative use calloc :-

     int rows = 2;
     int cols = 3;

    // Dynamically allocate memory for the 2D array using calloc
    int** arr = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
    arr[i] = (int*)calloc(cols, sizeof(int));
    }
     */
     

    // Assign values to the array elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;
        }
    }

    // Pass the array to the function
    printArray(arr, rows, cols);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}



/*
 **Malloc  Vs Calloc 


The main difference between malloc and calloc in C lies in how they allocate and initialize memory:

    Allocation:
        malloc: It allocates a block of memory of a specified size in bytes. The allocated memory is not initialized, meaning its content is indeterminate.
        calloc: It allocates a block of memory for a specified number of elements, each with a specified size in bytes. The allocated memory is initialized to zero.

    Initialization:
        malloc: The allocated memory is uninitialized. Its content is arbitrary and may contain garbage values.
        calloc: The allocated memory is initialized to zero. Each byte is set to the value 0.

    Arguments:
        malloc: It takes a single argument, the size of the memory block to be allocated in bytes.
        calloc: It takes two arguments, the number of elements to be allocated and the size of each element in bytes.

    Return Value:
        malloc and calloc both return a pointer to the allocated memory block if successful. If the allocation fails, they return a NULL pointer.

In summary, malloc is used for dynamic memory allocation without initialization, while calloc is used for dynamic memory allocation with zero initialization. The choice between malloc and calloc depends on whether you need the allocated memory to be initialized to zero or not.
 */

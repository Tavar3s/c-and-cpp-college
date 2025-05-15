#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

int main(void) {

    int* p = NULL;
    p = malloc(10 * sizeof(int)); // Allocate memory for 10 integers malloc(10*4) = 40 bytes
 

    *p = 5; // Assign the value 5 to the first element of the allocated memory
    *(p + 1) = 10; // Assign the value 10 to the second element of the allocated memory
    *(p + 2) = 15; // Assign the value 15 to the third element of the allocated memory

    free(p); // Free the allocated memory
    p = NULL; // Set the pointer to NULL after freeing the memory
    // Note: Accessing p after free(p) is undefined behavior, so we set it to NULL


    return 0;
}
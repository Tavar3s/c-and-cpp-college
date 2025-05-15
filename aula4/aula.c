#include <stdio.h>

int main(void) {
    int x = 3, y = 3, z = 3; // Dimensions of the 3D space
    int space[x][y][z];

    // Populate the 3D space with values
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                space[i][j][k] = i + j + k; // Example: sum of indices
            }
        }
    }

    // Print the 3D space
    printf("3D Space:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("space[%d][%d][%d] = %d\n", i, j, k, space[i][j][k]);
            }
        }
    }

    return 0;
}
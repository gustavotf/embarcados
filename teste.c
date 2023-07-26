#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

// Loop without unrolling 
void sum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    printf("Sum: %d\n", sum);
}


int main() {
    int array[ARRAY_SIZE];

    // Initialize the array
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    //time without loop unrolling
    clock_t start = clock();
    sum(array, ARRAY_SIZE);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);
    

    return 0;
}

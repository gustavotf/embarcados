#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

// Loop without unrolling 
void sum_without_unrolling(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    printf("Sum without unrolling: %d\n", sum);
}

// Loop with unrolling
void sum_with_unrolling(int array[], int size) {
    int sum = 0;
    int i;

    for (i = 0; i < size - 3; i += 4) {
        sum += array[i];
        sum += array[i + 1];
        sum += array[i + 2];
        sum += array[i + 3];
    }

    // remaining
    for (; i < size; i++) {
        sum += array[i];
    }

    printf("Sum with unrolling: %d\n", sum);
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
    sum_without_unrolling(array, ARRAY_SIZE);
    clock_t end = clock();
    double time_without_unrolling = ((double)(end - start)) / CLOCKS_PER_SEC;

    //time with loop unrolling
    start = clock();
    sum_with_unrolling(array, ARRAY_SIZE);
    end = clock();
    double time_with_unrolling = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken without unrolling: %f seconds\n", time_without_unrolling);
    printf("Time taken with unrolling: %f seconds\n", time_with_unrolling);

    return 0;
}

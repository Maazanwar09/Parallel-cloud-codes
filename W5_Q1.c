#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define ARRAY_SIZE 100000000 

long long sequential_sum(int *array, int size) {
    long long sum = 0; int i;
    for( i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

long long parallel_sum(int *array, int size, int num_threads) {
    long long sum = 0; int i;
    
    #pragma omp parallel for num_threads(num_threads) reduction(+:sum)
    for (i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}

int main() {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int)); int i; int num_threads;
    
    for ( i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100; 
    }

    clock_t start = clock();
    long long seq_sum = sequential_sum(array, ARRAY_SIZE);
    clock_t end = clock();
    double seq_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sequential sum: %lld, Time: %f seconds\n", seq_sum, seq_time);

    for ( num_threads = 2; num_threads <= 8; num_threads *= 2) {
        start = clock();
        long long par_sum = parallel_sum(array, ARRAY_SIZE, num_threads);
        end = clock();
        double par_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Parallel sum with %d threads: %lld, Time: %f seconds\n", num_threads, par_sum, par_time);
        printf("Speedup: %.2f, Efficiency: %.2f\n", seq_time / par_time, (seq_time / par_time) / num_threads);
    }

    free(array);
    return 0;
}

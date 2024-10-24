#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void double_array(int *array, int size) {
    int chunk_size = size / omp_get_max_threads();

    #pragma omp parallel 
    {
        int thread_id = omp_get_thread_num();
        int start_index = thread_id * chunk_size; 
        int end_index = (thread_id + 1) * chunk_size;
        int last_index = start_index; 

        if (thread_id == omp_get_num_threads() - 1) {
            end_index = size;
        }

        for (int i = start_index; i < end_index; i++) {
            array[i] *= 2;
            last_index = i; 
        }

        #pragma omp single nowait
        {
            printf("Thread %d processed up to index %d\n", thread_id, last_index);
        }
    }
}

int main() {
    int size = 100000; 
    int *array = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = i + 1; 
    }

    double_array(array, size);

    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}


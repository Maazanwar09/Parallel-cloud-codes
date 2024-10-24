#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int arr[SIZE];

    #pragma omp parallel firstprivate(arr)
    {
        int thread_id = omp_get_thread_num();
        int chunk_size = SIZE / omp_get_num_threads(); 
        int start_value = thread_id * chunk_size + 1; 
        int end_value = start_value + chunk_size - 1; 
        int last_value,i; 

        #pragma omp for nowait
        for ( i = start_value; i < end_value; i++) {
            arr[i - 1] = i; 
            last_value = i; 
        }

        #pragma omp lastprivate(last_value)
        {
            printf("Thread %d initialized up to value %d\n", thread_id, last_value);
        }
    }


    printf("First element: %d\n", arr[0]);
    printf("Last element: %d\n", arr[SIZE - 1]);

    return 0;
}

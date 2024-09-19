#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 4;

    #pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        printf("Hello world from thread %d\n", thread_id);
    }

    return 0;
}


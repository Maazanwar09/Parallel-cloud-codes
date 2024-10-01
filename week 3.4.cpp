#include<stdio.h>
#include<omp.h>
int main(){
	int num_threads=4;
	omp_set_num_threads(num_threads);
	#pragma omp parallel for
	for(int i=0;i<100;i++){
		int thread_id=omp_get_thread_num();
		printf("Hello world from thread(%d) iteration %d\n",thread_id,i);
	}
	return 0;
}

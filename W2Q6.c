#include<stdio.h>
#include<omp.h>
int main(){
	int arr[20]={1,2,3,4,5,6,7,8,9,10,11,45,67,65,34,79,80,37,54,90}, i ;

#pragma omp parallel for
for(i=0;i<20;i++){

if(arr[i]%2 == 0){
	printf("thread %d: %d is even \n", omp_get_thread_num(),arr[i]);
	
}else{
	printf("thread %d: %d is odd \n", omp_get_thread_num(),arr[i]);
}
}
return 0;
}

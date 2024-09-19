#include<stdio.h>
#include <omp.h>
#include<math.h>
int main (){
	int arr[20]={153,370,371,407,678,543,980,790,675,453,236,538,806,508,405,293,893,503,904,419};
	int sum=0,num, rem, tid;
	int i;
	#pragma omp for private(num,rem,sum)
	for(i = 0;i<20;i++){
		tid=omp_get_thread_num();
		num=arr[i];
		sum=0;
		while(num!=0){
			rem=num%10;
			sum+=rem*rem*rem;
			num/=10;
		}
		if(sum==arr[i]){
			printf("%d is an Armstrong number from thread %d\n", arr[i],tid);
		}
		else{
			printf("%d is not an armstrong number from thread %d\n",arr[i],tid);
		}
	}
	
return 0;
}

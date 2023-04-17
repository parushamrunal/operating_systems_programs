#include<stdio.h>
#include<pthread.h>
void *comp(void *add);
int main(){
	pthread_t thread1;
	pthread_t thread2;
	long val1 = 1;
	long val2 = 2;
/*	comp((void*)&val1);
	comp((void*)&val2);*/
	pthread_create(&thread1, NULL, comp, (void*)&val1);
	pthread_join(thread1, NULL);
	pthread_create(&thread2, NULL, comp, (void*)&val2);
	pthread_join(thread2, NULL);
	return 0;
}
void *comp(void *add){
	long sum = 0;
	long *add_num = (long*) (add);
	for(long i=0;i<100;i++)
		sum +=*add_num;
	printf("add:%ld\n",*add_num);
	return 0;
}

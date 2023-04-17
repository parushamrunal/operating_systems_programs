#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *add();
//int a=1;
int main(){
	pthread_t t1;
	pthread_t t2;
	int s, t;
	s = pthread_create(&t1, NULL, add, NULL);
	printf("t1:%ld\n",t1);
	if(s != 0){
		printf("not created successfully\n");
	}else{
		printf("created\n");
	}
	t = pthread_create(&t2, NULL, add, NULL);
	printf("t2:%ld\n",t2);
	if(s != 0){
		printf("not created\n");
	}else{
		printf("created\n");
	}
	s = pthread_join(t1, NULL);
	t = pthread_join(t2, NULL);
	return 0;
}
void *add(){
	int a=10;
	int b=20;
	int sum = 0;
	sum = a + b;
	printf("sum:%d\n",sum);
	printf("fun:%ld\n",pthread_self());
//	printf("sub:%d\n",a-b);
//	printf("mul:%d\n",a*b);
//	printf("div:%d\n",b/a);
	return 0;
}

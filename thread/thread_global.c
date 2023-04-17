#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex;
int static g_v=10;
void *fun1();
void *fun2();
void *fun3();
int main(){
	pthread_t t1,t2,t3;
	int s;
	s = pthread_create(&t1, NULL, &fun1, NULL);
	if(s != 0){
		printf("not created\n");
	}else{
		printf("created\n");
	}
	s = pthread_create(&t2, NULL, &fun2, NULL);
	if(s != 0){
		printf("not created\n");
	}else{
		printf("created\n");
	}
	s = pthread_create(&t3, NULL, &fun3, NULL);
	if(s != 0){
		printf("not created\n");
	}else{
		printf("created\n");
	}
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
}
void *fun1(){
pthread_mutex_lock(&mutex);
	while(g_v){
		sleep(3);
		g_v++;
		printf("fun1 : %d\n", g_v);
		if(g_v == 100){
			break;
		}
	}
pthread_mutex_unlock(&mutex);
}
void *fun2(){
pthread_mutex_lock(&mutex);
	while(g_v){
		sleep(3);
		g_v++;
		printf("fun2 : %d\n", g_v);
		if(g_v == 100){
			break;
		}
	}
pthread_mutex_unlock(&mutex);
}
void *fun3(){
pthread_mutex_lock(&mutex);
	while(g_v){
		sleep(3);
		g_v++;
		printf("fun3 : %d\n", g_v);
		if(g_v == 100){
			break;
		}
	}
pthread_mutex_unlock(&mutex);
}

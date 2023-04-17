#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex;
void *fun1();
void *fun2();
void *fun3();
int g_v = 10;
int main(){
	pid_t pid1, pid2, pid3;
	pid1 = fork();
	if(pid1 == 0){
		printf("child1\n");
		fun1();
	}else{
		printf("parent1\n");
		pid2 = fork();
		if(pid2 == 0){
			printf("child2\n");
			fun2();
		}else{
			printf("parent2\n");
				fun3();
			}
	}
}
void *fun1(){
pthread_mutex_lock(&mutex);
        while(g_v){
                sleep(3);
                g_v++;
                printf("fun1 : %d\n", g_v);
                if(g_v == 10){
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
                if(g_v == 10){
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
                if(g_v == 10){
                        break;
                }
        }
pthread_mutex_unlock(&mutex);
}

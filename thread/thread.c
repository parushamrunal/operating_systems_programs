#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* func(void* p) {
	printf("From the function, the thread id = %ld\n", pthread_self()); //get current thread id
   	pthread_exit(NULL);
   	return NULL;
}
int main() {
   	pthread_t thread; // declare thread
   	pthread_create(&thread, NULL, func, NULL);
   	printf("From the main function, the thread id = %ld\n", thread);
   	pthread_join(thread, NULL); //join with main thread
}

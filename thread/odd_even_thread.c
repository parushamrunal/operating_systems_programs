#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t mutex;
int r;
int shared_data;
void *even(void *aa){
    pthread_mutex_lock(&mutex);
    while(shared_data <= 10){
        if(shared_data%2==0){
            printf("Even-%d\n",shared_data);
            shared_data++;
        } else{
            r= pthread_mutex_unlock(&mutex);
        }
}
return NULL;
}
void *odd(void *aa){
    r=pthread_mutex_lock(&mutex);
    while(shared_data <= 10){
        if(shared_data %2 !=0){
            printf("Odd-%d\n", shared_data);
            shared_data++;
        }else{
            pthread_mutex_unlock(&mutex);
        }
    } return NULL;
}
int main(void) {
    pthread_t p1[2];
    pthread_mutex_init(&mutex,NULL);
    if(pthread_create(&p1[0],NULL,&even,NULL)!=0){
        printf("Error in thread creation");
        return 1;
    }
    if(pthread_create(&p1[1],NULL,&odd,NULL)!=0){
        printf("Error in thread creation");
        return 1;
    }
    pthread_join(p1[0],NULL);
    pthread_join(p1[1],NULL);
    return 0;
}

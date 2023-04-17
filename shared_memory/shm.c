#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
int main(void)
{
    const char * SHM_NAME = "/mine";
    const int SHM_SIZE = 4096;
    char *message = NULL ;
    char buff[100];
    message = (char *)malloc (sizeof(char)* SHM_SIZE);
    int fd = shm_open(SHM_NAME , O_CREAT | O_RDWR , 0666);
    if(fd == -1){
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    if(ftruncate(fd,SHM_SIZE)==-1){
        perror("ftrunate");
        exit(EXIT_FAILURE);
    }
    void * shm_ptr = mmap(NULL,SHM_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if(shm_ptr == MAP_FAILED){
    perror("mmap");
    exit(EXIT_FAILURE);
    }
    printf("Enter the message\n");
    fgets(message,100,stdin);
    strncpy(shm_ptr,message,strlen(message));
    strncpy(buff, shm_ptr, strlen(message));
    printf("message in shared memory %s",buff);
    if(munmap(shm_ptr,SHM_SIZE)==-1){
        perror("unmap");
        exit(EXIT_FAILURE);
    }
    if(close(fd)==-1){
        perror("close");
        exit(EXIT_FAILURE);
    }
    if(shm_unlink(SHM_NAME)==-1){
        perror("unlink");
        exit(EXIT_FAILURE);
    }
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#define NAME "MESSAGE_QUEUE"
#define NUM 3
#define SIZE (NUM * sizeof(int))
int main(void){
	int fd = shm_open(NAME, O_RDONLY, 0660);//create and opening shared memory
	if( fd < 0 ){//checking validation
		perror("shm_open()");
        return EXIT_FAILURE;
	}
	int *data = (int*)mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);//map the share memory segmenet into the process address space
	printf("receiver mapped address: %p\n",data);
	for(int i = 0; i < NUM; ++i){
        printf("%d\n", data[i]);
    }
    munmap(data, SIZE);//unmaps the shared memory item
    close(fd);
	shm_unlink(NAME);//close the shared message
    return EXIT_SUCCESS;
}

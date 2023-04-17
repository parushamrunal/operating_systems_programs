#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#define NAME "SHARED_MEMORY"
#define NUM 10
#define SIZE (NUM * sizeof(int))
int main(void) {
	int fd = shm_open(NAME, O_CREAT | O_EXCL | O_RDWR , 0660);//creating share memory
	if( fd < 0 ){// checking the validation
		perror("shm_open()");
		return EXIT_FAILURE;
	}
	ftruncate(fd, SIZE);// set size of the shared memory segment
	int *data = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);//map the shared memory segment into the process adress space
	printf("sender mapped address: %p\n",data);
	for(int i = 0; i < NUM; ++i){
		data[i] = i;
	}
	munmap(data, SIZE);//unmaps the shared memory item
	close(fd);
	return EXIT_SUCCESS;
}

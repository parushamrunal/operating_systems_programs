//one side of fifi it write first then read
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main(void) {
	int fd;
	char *myfifo = "myfifo";//fifo file path
	//mkfifo creating named pipe using system call
	// mkfifo (<oathname>,<permissions>)
	mkfifo(myfifo, 0666);
	char arr1[50],arr2[50];
	while(1)
		{
			//open fifo for write only
			fd = open(myfifo , O_WRONLY);
			//take user i/p
			fgets(arr2, 50, stdin);
			//write the i/p
			write(fd, arr2, sizeof(arr2));
			// close the pipe
			close(fd);
			// open fifo for read only
			fd = open(myfifo, O_RDONLY);
			//read from fifo
			read(fd, arr1, sizeof(arr1));
			if(strncmp("bye\n",arr1,3))
				{
					exit(EXIT_SUCCESS);
				}
			//print the message
			printf("user 2:%s", arr1);
			//close the fifo
			close(fd);
		}
	return 0;
}

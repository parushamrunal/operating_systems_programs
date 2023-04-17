//one side of fifo it reads first and the writes
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(void) {
	int fd1;
    char *myfifo = "myfifo";//fifo file path
    //mkfifo creating named pipe using system call
    // mkfifo (<oathname>,<permissions>)
    mkfifo(myfifo, 0666);
    char str1[50],str2[50];
    while(1)
   	{
        //open fifo for read only
        fd1 = open(myfifo , O_RDONLY);
		//read from fif0
        read(fd1, str1, 50);
		//print message
		printf("user 1:%s",str1);
        // close the pipe
        close(fd1);
        // open fifo for write only
        fd1 = open(myfifo, O_WRONLY);
        //input from user
        fgets(str2, 50, stdin);
		//write
		write(fd1, str2, sizeof(str2));
		if(strncmp("bye\n",str2,3))
			{
				exit(EXIT_SUCCESS);
			}
		//close
		close(fd1);
	}
	return 0;
}

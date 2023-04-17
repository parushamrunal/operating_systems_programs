#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char * argv[])
{
    printf("Hello world\n");
    write(STDOUT_FILENO, "Ciao\n", 5);
    //fflush(stdout);
    if (fork() == -1)
    printf("Child is not created\n");
/* Both child and parent continue execution here */
    exit(EXIT_SUCCESS);
}

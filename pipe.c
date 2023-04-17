#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 50
int main(void)
{
    int pipefds[2];
    int status;
    pid_t pid;
    char *wmsg, *rmsg;                                  // write and read pointers
    wmsg = (char *)malloc(sizeof(char)*SIZE);           // dynamically alocating memory for write
    rmsg = (char *)malloc(sizeof(char)*SIZE);           //dynamically allocating memory for read
    printf("enter a message\n"); 
    fgets(wmsg,SIZE,stdin);                             //getting user input         
    status = pipe(pipefds);                                
    if(status == -1) {                                     // checking wheather pipe created or not
        printf("files are not created.\n");
        exit(EXIT_FAILURE);
    }
    pid = fork();                                       //checking new process created or not
    if(pid == -1){
    	printf("fork not created\n");   
        exit(EXIT_FAILURE);
    } else if(pid == 0) {                               //checking condition for child
    	printf("child process\n");
        read(pipefds[0], rmsg, SIZE);                   //reading the pipe
        printf("rmsg: %s\n",rmsg);
    } else {
    	printf("parent process\n");                     //checking condition for parent
        write(pipefds[1], wmsg, SIZE);                  //writing the pipe
        printf("wmsg :%s",wmsg);
    }
}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void) {
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		printf("parent crated");
	}
	else {
		execlp("mrunal.txt","w");
		
	}
	return 0;
}

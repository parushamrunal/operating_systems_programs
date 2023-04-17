#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void) {
	FILE *fp;
	char ch[200];
	pid_t pid;
	pid = fork();
	fp = fopen("mrunal.txt","r");
	if(pid==0){
		printf("child process:");
		while(fgets(ch,200,fp)!=NULL){
			printf("%s",ch);
		}
	} else if(pid > 0) {
		wait(NULL);
		printf("parent process:");
		while(fgets(ch,200,fp)!=NULL){
			printf("%s",ch);
		}
	fclose(fp);
	} else {
		printf("failed");
	}
	return 0;
}

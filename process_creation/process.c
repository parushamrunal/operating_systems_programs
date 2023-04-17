#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int global_val=10;
int main(void) {
        int a=10;
//		int global_val=20;
        pid_t pid = fork();
        if(pid==0)      {
				int global_val=100;
                printf("\n");
                printf("child created");
                printf("\n");
                printf("%d",getpid());
                printf("\n");
                printf("%d",pid);
				printf("\n");
				printf("val:%d",global_val);
				printf("\n");
        } else {
				wait(NULL);
                printf("parent created");
                printf("\n");
                printf("%d",getpid());
                printf("\n");
                printf("%d",pid);
				printf("\n");
				printf("val:%d",global_val);
        }
        return 0;
}

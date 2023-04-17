#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>
#include<string.h>
int main(void)
{
    mqd_t mqd;
    char buffer[8192];
//    char buf[8192];
    struct mq_attr attr;
    ssize_t numRead;
    mqd = mq_open("/mymq", O_RDWR);
//    while(1){  
       numRead = mq_receive(mqd, buffer, 8192, 0);
    if (numRead == -1)
        printf("mq_receive error\n");
    printf("from sender: %s",buffer);
//        printf("Receiver:");
//        fgets(buf,100,stdin);
  //      mq_send(mqd, buf, strlen(buf), 0);
  //  }
}

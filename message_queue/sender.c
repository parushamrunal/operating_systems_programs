#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>
#include<string.h>
#define SIZE 100
int main(void)
{
    mqd_t mqd;
    char buf[8192], buffer[8192];
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 8192;
    attr.mq_curmsgs = 0;
    mqd = mq_open("/mymq",O_CREAT | O_RDWR, 0744, &attr);
    if (mq_getattr(mqd, &attr) == -1)
    printf("mq_getattr error\n");
//    while(1) {
        printf("sender:");
        fgets(buf,SIZE,stdin);
        mq_send(mqd, buf, strlen(buf), 0);
//        mq_receive(mqd, buffer, attr.mq_msgsize, 0);
  //      printf("from Receiver: %s",buffer);
  //  }
    mq_unlink("mymq");
}







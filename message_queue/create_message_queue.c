#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main() {
    mqd_t mq; // message queue descriptor
    char *msg = "Hello, world!";
    struct mq_attr attr;    
    // set the message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 20;
    attr.mq_curmsgs = 0;
    // create the message queue
    mq = mq_open("/myqueue", O_CREAT | O_RDWR, 0644, &attr);
    if (mq == (mqd_t) -1) {
        perror("mq_open");
        exit(1);
    }
    // send a message to the queue
    if (mq_send(mq, msg, 14, 0) == -1) {
        perror("mq_send");
        exit(1);
    }
    // close the message queue
    mq_close(mq);
   	printf("message:%s\n",msg); 
	return 0;
}

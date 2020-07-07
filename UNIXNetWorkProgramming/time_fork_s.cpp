#include "unp.h"
#include <time.h>
#include "my_err.h"
#include "apue.h"

int main()
{
    char buff[MAXLINE];
    time_t ticks;
    struct sockaddr_in servaddr;
    pid_t pid;
    int listenfd,connfd;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bind(listenfd, (SA*)&servaddr,sizeof(servaddr));
    listen(listenfd,LISTENQ);

    for(; ;) {
        connfd = accept(listenfd,(SA*)NULL,NULL);

        if((pid = fork()) == 0) {
            //子进程
            close(listenfd);
            snprintf(buff,sizeof(buff),"%.24s\r\n", ctime(&ticks));
            write(connfd, buff, strlen(buff));
            close(connfd);
            exit(0);
        }
        close(connfd);
    }

}


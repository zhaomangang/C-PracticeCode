#include "unp.h"
#include <time.h>
#include "my_err.h" 
int main(int argc, char **argv){
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    if((listenfd = socket(AF_INET,SOCK_STREAM,0))<0) {
        err_sys("socket error");
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    if(bind(listenfd, (SA*) &servaddr, sizeof(servaddr))<0) {
        err_sys("bin error");
    }

    /*
     *1、listn函数将该套接字转化为一个监听套接字，这样来自客户的外来连接就可在该套接字上由内核接受
     *2、socket、bind、listen这三个步骤是任何TCP服务器准备所谓的监听描述符的正常步骤
     *3、LISTENQ在unp.h中定义。他是指系统内核允许在这个监听描述符上排队的最大客户连接数
     *
     * */
    listen(listenfd,LISTENQ);
    


    /*
     *  通常情况下，服务器进程在accept调用中被投入睡眠，等待某个客户连接的到达
     *并被内核接受。TCP连接使用所谓的三路握手来建立连接。握手完毕时accept返回，
     *其返回值是一个称为已连接描述符的新描述符。该描述符用于与新进连接的那个客
     *户通信。accept为每个连接到本服务器的客户返回一个新描述符
     *
     * */
    for( ; ; ) {
        connfd = accept(listenfd, (SA*) NULL, NULL);

        ticks = time(NULL);
        /*
         *sprintf函数无法检查目的缓冲区是否溢出。相反，snprintf要求其第二个参数指定目的的
         * 缓冲区大小，因此可以确保该缓冲区不溢出
         * */
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

        close(connfd);
    }

}

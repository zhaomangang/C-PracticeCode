#include "unp.h"
#include "my_err.h"
int main(int argc, char **argv)
{
    int sockfd,n;   
    char recvline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if (argc!=2)
        err_quit("usage:a.out <ipadress>");
    /*
     * socket函数创建一个网际(AF_INET)字节流套接字(SOCK_STREAM)，他是TCP套接字的花哨名字。
     * 该函数返回一个小整数描述符，以后所有函数调用就用该描述符来标识这个套接字
     *
     * */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");
    
    /*
     * extern void bzero(void *s, int n)
     * 置字节字符串s的前n个字节为零且包括‘\0‘
     *
     * */
    bzero(&servaddr, sizeof(servaddr));

    /*
     * 设置网际套接字结构体的地址族和端口号
     *
     * */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    
    /*
     *inet_pton:把ascall命令行参数转换为特定的ip格式
     *
     * */
    if(inet_pton(AF_INET,argv[1], &servaddr.sin_addr) <= 0)
        err_quit("inet_pton error for %s",argv[1]);
    
    /*
     *connect函数应用于一个TCP套接字时，将与由他第二个参数指向的套接字地址结构指定的服务器建立
     * 一个TCP链接。
     * 该套接字地址结构的长度也必须作为该函数的第三个参数指定，对于网际套接字地址结构，用sizeof来计算
     *
     * 每当一个套接字函数需要一个指向某个套接字地址结构的指针时，这个指针必须强制类型转换成一个指向
     *通用套接字地址结构的指针。
     *由于struct_sockaddr比较长因此在unp.h头文件中#define SA struct sockaddr。此处直接使用SA*
     *
     *
     * */
    if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) <0 )
        err_sys("connect error");

    while( (n = read(sockfd, recvline, MAXLINE))>0 ) {
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF)
            err_sys("fputs error");
    }

    if(n<0)
        err_sys("read error");

    exit(0);
}

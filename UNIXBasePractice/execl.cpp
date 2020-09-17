#include<unistd.h>
#include <sys/types.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
    pid_t pid;

    //父进程数数
    for(int i=0;i<8;++i)
    {
        cout<<"parent i = "<<i<<endl;
    }
    
    //创建子进程
    pid = fork();
    //让子进程执行ls命令
    if(pid == 0)
    {
        //子进程
        execl("/bin/l","ls ","-al",NULL);
        perror("execl");
        exit(1);
    }
    for(int i = 0; i < 3 ;i++)
    {
        cout<<"parent i is "<<i<<endl;
    }

    return 0;
}

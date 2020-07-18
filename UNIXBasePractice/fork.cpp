#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;
int main()
{
    pid_t pid;
    int number = 0;
    cout<<"main函数,my parent is "<<getppid()<<" "<<number<<endl;
    pid = fork();
    if(pid < 0) {
        cout<<"进程创建失败"<<endl;
    }else if(pid == 0){
       // while(number < 5000)
        {
            number++;
            cout << "这里是子进程"<<number<<endl;
        }
    }else {
        number = 7;
       // while(number < 100000)
        {
            number++;
            cout<<"我是父进程 childpid = "<<pid<<" number"<<number<<"mypid"<<getpid()<<endl;
        }   
    }


    return 0;
}

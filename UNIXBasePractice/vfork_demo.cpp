#include "apue.h"
#include "my_err.h"

int globvar = 6;

int main()
{
    int var;
    pid_t pid;
    var = 88;
    printf("befor vfork\n");
    if ((pid = vfork()) < 0 ) {
        err_sys("vfork eror");
    }else if (pid == 0) {
        //子进程
        globvar++;
        var++;
        _exit(0);
    }
    printf("pid = %ld,glob = %d, var = %d\n",(long)getpid(),globvar,var);
    exit(0);
}

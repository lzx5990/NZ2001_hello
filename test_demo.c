#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    if((pid = fork()) < 0)
    {
        perror("fail to fork");
        exit(1);
    }
    else if(pid > 0) //父进程
    {
        printf("This is parent process\n");

        //当创建子进程后，如果子进程退出但是父进程没有退出，此时子进程的状态为僵尸态
        //所以称之为僵尸进程，僵尸进程还会占用资源，所以需要处理

        //处理方法1：父进程退出，子进程从僵尸进程变成孤儿进程，会被新的父进程回收资源   

        //处理方法2：使用wait或者waitpid函数，wait函数是阻塞等待子进程的退出状态，
        //如果子进程退出了，父进程会通过wait函数回收子进程的资源，可以处理僵尸进程
        sleep(10);
        wait(NULL);
        printf("僵尸进程已经处理\n");

        //处理方法3：由于wait函数是阻塞函数，所以使得父进程无法正常向下运行
        //所以最好的处理方式是使用信号
        while(1)
        ;
    }
    else  //子进程
    {
        printf("This is child process\n");
        sleep(5);

        printf("The child process is quiting\n");
        exit(0);
    }

    return 0;
}
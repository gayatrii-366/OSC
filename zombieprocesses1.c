#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main()
{    int pid = fork();
     if (pid > 0){
           printf("parent  process id%d\n", getpid());
           printf("\n child process id %d\n", pid);
           }
     else if (pid == 0)
           { sleep(1);
           printf("\n child process id %d\n", getpid());
           printf("\n parent process  id %d\n", getppid());
           }
     return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t num_pid;
void main()
{
    num_pid=fork(); 
    if(num_pid<0)
        printf("Error in fork execution");
        
    else
    if(num_pid==0)
    {
        printf("this is the child process id %d\n",getpid());
        printf("this is the child  p process id %d\n",getppid());
     }   
    else
    {
        wait(NULL);
        printf("this is the parent id %d\n",getpid());
        
    }
    exit(0);
}

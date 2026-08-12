#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    pid_t pid;
    if((pid=fork()) < 0)
        printf("\tfork error\n");
    else
    if(pid==0)
        printf("child process id is %d\n",getpid());
    else
    {
        sleep(10);
        printf("*****parent\n");
        system("ps -axj | tail");
    }
}
/*
computer@computerVY:~$ gedit zombieprocesses.c
computer@computerVY:~$ gcc zombieprocesses.c -o zombie
computer@computerVY:~$ ./zombie
child process id is 5673
*****parent
   2307    5355    2307    2307 ?             -1 Sl    1000   0:00 /usr/libexec/gvfsd-network --spawner :1.21 /org/gtk/gvfs/exec_spaw/1
   2307    5364    2307    2307 ?             -1 Sl    1000   0:00 /usr/libexec/gvfsd-dnssd --spawner :1.21 /org/gtk/gvfs/exec_spaw/2
      2    5408       0       0 ?             -1 I        0   0:00 [kworker/11:1]
      2    5422       0       0 ?             -1 I        0   0:00 [kworker/2:0-cgroup_free]
      2    5587       0       0 ?             -1 I        0   0:00 [kworker/u48:0]
   3254    5672    5672    3254 pts/0       5672 S+    1000   0:00 ./zombie
   5672    5673    5672    3254 pts/0       5672 Z+    1000   0:00 [zombie] <defunct>
   5672    5678    5672    3254 pts/0       5672 S+    1000   0:00 sh -c -- ps -axj | tail
   5678    5679    5672    3254 pts/0       5672 R+    1000   0:00 ps -axj
   5678    5680    5672    3254 pts/0       5672 S+    1000   0:00 tail
computer@computerVY:~$ ^C
*/

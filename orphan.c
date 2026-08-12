#include <stdio.h>
#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        sleep(5);
        printf("Child is running. Parent ID = %d\n", getppid());
    }
    else
    {
        printf("Parent is terminated.\n");
    }

    return 0;
}
/*
gayatrii-366@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc orphan.c -o orphan
gayatrii-366@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./orphan
Parent is terminated.

Child is running. Parent ID = 364
*/

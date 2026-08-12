#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int a[] = {5, 2, 8, 1, 3};
    int n = 5, i, j, temp;

    if (fork() == 0)
    {
        // Child: Descending
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] < a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

        printf("Child: Descending order: ");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else
    {
        // Parent: Ascending
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

        printf("Parent: Ascending order: ");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        wait(NULL);
    }

    return 0;
}/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit parent_sort.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc parent_sort.c -o sort
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./sort
Child: Descending order: 8 5 3 2 1 Parent: Ascending order: 1 2 3 5 8
*/


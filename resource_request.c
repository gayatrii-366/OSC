#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], work[m], finish[n], safe[n];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int pid;
    int request[m];

    printf("\nEnter the process number making the request (0 to %d): ", n - 1);
    scanf("%d", &pid);

    printf("Enter the request vector for P%d:\n", pid);
    for(j = 0; j < m; j++)
    {
        scanf("%d", &request[j]);
    }

    for(j = 0; j < m; j++)
    {
        if(request[j] > need[pid][j])
        {
            printf("\nError: Process P%d exceeded its maximum claim (Request > Need).\n", pid);
            return 0;
        }
    }

    for(j = 0; j < m; j++)
    {
        if(request[j] > available[j])
        {
            printf("\nProcess P%d must wait. Resources are not available right now.\n", pid);
            return 0;
        }
    }

    for(j = 0; j < m; j++)
    {
        available[j] -= request[j];
        allocation[pid][j] += request[j];
        need[pid][j] -= request[j];
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    for(i = 0; i < m; i++)
        work[i] = available[i];

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1)
                {
                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nRequest cannot be granted immediately. It leads to an unsafe state.\n");
            return 0;
        }
    }

    printf("\nRequest by P%d can be granted safely!", pid);
    printf("\nSafe Sequence: ");
    for(i = 0; i < n; i++)
    {
        printf("P%d", safe[i]);
        if(i != n - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}

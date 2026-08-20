#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], st[n], ct[n], tat[n], wt[n];
    int total_tat = 0, total_wt = 0;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    st[0] = at[0];
    ct[0] = st[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i - 1] > at[i]) {
            st[i] = ct[i - 1];
        } else {
            st[i] = at[i];
        }
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++) {
        printf(" P%d |", i + 1);
    }
    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("   %d", ct[i]);
    }
    printf("\n");

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);

    return 0;
}

#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, shortest;
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    int gantt[1000];
    float sum_tat = 0, sum_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed != n) {
        shortest = -1;
        int min_rt = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            gantt[time] = 0;
            time++;
            continue;
        }

        gantt[time] = shortest + 1;
        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            sum_tat += tat[shortest];
            sum_wt += wt[shortest];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT: %.2f ms\nAvg WT:  %.2f ms\n", sum_tat / n, sum_wt / n);

    printf("\nGantt Chart:\n0");
    int last = gantt[0];
    for (int i = 1; i <= time; i++) {
        if (i == time || gantt[i] != last) {
            if (last == 0) printf(" -> [IDLE] -> %d", i);
            else printf(" -> [P%d] -> %d", last, i);
            
            if (i < time) last = gantt[i];
        }
    }
    printf("\n");

    return 0;
}

/*

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit OS_exp4b_SRTF.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc OS_exp4b_SRTF.c -o osexp4b
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./osexp4b
Enter number of processes: 5
Enter AT and BT for P1: 12
4
Enter AT and BT for P2: 6
22
Enter AT and BT for P3: 5
6
Enter AT and BT for P4: 1
55
Enter AT and BT for P5: 2
4

PID     AT      BT      CT      TAT     WT
P1      12      4       16      4       0
P2      6       22      38      32      10
P3      5       6       12      7       1
P4      1       55      92      91      36
P5      2       4       6       4       0

Avg TAT: 27.60 ms
Avg WT:  9.40 ms

Gantt Chart:
0 -> [IDLE] -> 1 -> [P4] -> 2 -> [P5] -> 6 -> [P3] -> 12 -> [P1] -> 16 -> [P2] -> 38 -> [P4] -> 92
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/

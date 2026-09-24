#include <stdio.h>

int main() {
    int n, f;

    printf("Enter number of incoming pages: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int pages[n];
    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    if (scanf("%d", &f) != 1 || f <= 0) return 1;

    int frames[f];
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    int page_faults = 0;
    int page_hits = 0;
    int index = 0;

    printf("\nPage\tFrames\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int hit = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                hit = 1;
                page_hits++;
                break;
            }
        }

        if (!hit) {
            frames[index] = page;
            index = (index + 1) % f;
            page_faults++;
        }

        printf("%d\t", page);
        for (int j = 0; j < f; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        if (hit) {
            printf("\t(Hit)\n");
        } else {
            printf("\t(Fault)\n");
        }
    }

    printf("\nTotal Hits: %d\n", page_hits);
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

/*computer@computerVY:~$ gcc page_replacement.c
computer@computerVY:~$ ./a.out
Enter number of incoming pages: 12
Enter the page reference sequence:
2
3
3
1
5
2
4
5
3
2
2
5
Enter number of frames: 3

Page	Frames
2	2 - - 	(Fault)
3	2 3 - 	(Fault)
3	2 3 - 	(Hit)
1	2 3 1 	(Fault)
5	5 3 1 	(Fault)
2	5 2 1 	(Fault)
4	5 2 4 	(Fault)
5	5 2 4 	(Hit)
3	3 2 4 	(Fault)
2	3 2 4 	(Hit)
2	3 2 4 	(Hit)
5	3 5 4 	(Fault)

Total Hits: 4
Total Page Faults: 8
*/

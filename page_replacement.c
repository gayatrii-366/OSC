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

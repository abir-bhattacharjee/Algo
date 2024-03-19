#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort jobs based on profit-to-deadline ratio using bubble sort
void sortJobs(int *profits, int *deadlines, int *jobIDs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((float)profits[j] / deadlines[j] < (float)profits[j + 1] / deadlines[j + 1]) {
                swap(&profits[j], &profits[j + 1]);
                swap(&deadlines[j], &deadlines[j + 1]);
                swap(&jobIDs[j], &jobIDs[j + 1]);
            }
        }
    }
}

int jobSequencing(int *profits, int *deadlines, int *jobIDs, int n) {
    sortJobs(profits, deadlines, jobIDs, n);

    int maxProfit = 0;
    int finishedJobs = 0;
    int lastFinishTime = 0;

    for (int i = 0; i < n; i++) {
        int availableSlot = -1;

        // Find the latest available slot before the deadline
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (finishedJobs > j) {
                availableSlot = j;
                break;
            }
        }

        if (availableSlot != -1) {
            finishedJobs++;
            maxProfit += profits[i];
            lastFinishTime = deadlines[i];
        }
    }

    return maxProfit;
}

int main() {
    int profits[] = {100, 19, 27, 25, 15};
    int deadlines[] = {2, 1, 2, 1, 2};
    int jobIDs[] = {1, 2, 3, 4, 5};
    int n = sizeof(profits) / sizeof(profits[0]);

    int maxProfit = jobSequencing(profits, deadlines, jobIDs, n);

    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}

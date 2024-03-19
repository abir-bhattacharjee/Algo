#include <stdio.h>

void bubbleSort(int duration[], int profit[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profits
                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                // Swap durations accordingly
                int tempDuration = duration[j];
                duration[j] = duration[j + 1];
                duration[j + 1] = tempDuration;
            }
        }
    }
}

void jobSequencing(int duration[], int profit[], int n) {
    bubbleSort(duration, profit, n);

    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = -1; // Initialize result array with -1
    }

    for (int i = 0; i < n; i++) {
        for (int j = duration[i] - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i; // Assign job to the slot
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i] + 1); // Print job index (1-based)
        }
    }
    printf("\n");
}

int main() {
    int duration[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};
    int n = sizeof(duration) / sizeof(duration[0]);

    jobSequencing(duration, profit, n);

    return 0;
}

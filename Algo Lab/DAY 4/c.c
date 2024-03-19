#include<stdio.h>

struct job {
    int id, deadline, profit;
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobSequencing(struct job a[], int n) {
    int maxDeadline = 0;
    // Find the maximum deadline among all jobs
    for (int i = 0; i < n; i++) {
        if (a[i].deadline > maxDeadline) {
            maxDeadline = a[i].deadline;
        }
    }
    
    // Array to represent time slots
    int timeslots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        timeslots[i] = -1; // Initialize all slots as empty (-1 represents no job)
    }

    // Assign jobs to time slots
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, a[i].deadline) - 1; j >= 0; j--) {
            if (timeslots[j] == -1) {
                timeslots[j] = a[i].id; // Assign job to time slot
                totalProfit += a[i].profit;
                break;
            }
        }
    }

    // Output total profit and job sequence
    printf("Total Profit: %d\n", totalProfit);
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (timeslots[i] != -1) {
            printf("%d ", timeslots[i]);
        }
    }
}

int main() {
    struct job a[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter id, deadline, profit for job %d: ", i + 1);
        scanf("%d %d %d", &a[i].id, &a[i].deadline, &a[i].profit);
    }

    // Sort the jobs based on profit in non-increasing order
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (a[j].profit < a[j + 1].profit) {
                struct job temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    jobSequencing(a, 4);

    return 0;
}

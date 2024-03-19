#include <stdio.h>

// Function to perform bubble sort based on value-to-weight ratio
void bubbleSort(int profit[], int weight[], double ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Sort items based on value-to-weight ratio
            if (ratio[j] < ratio[j + 1]) {
                // Swap profits
                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                // Swap weights accordingly
                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                // Swap ratios accordingly
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
            }
        }
    }
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int W, int profit[], int weight[], int n) {
    // Calculate value-to-weight ratio for each item
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }

    // Sort items based on value-to-weight ratio using bubble sort
    bubbleSort(profit, weight, ratio, n);

    double totalProfit = 0.0;
    int currentWeight = 0;

    // Iterate through the sorted items
    for (int i = 0; i < n; i++) {
        // If adding the entire item doesn't exceed the knapsack capacity
        if (currentWeight + weight[i] <= W) {
            totalProfit += profit[i];
            currentWeight += weight[i];
        } else {
            // Add a fraction of the item to fill the knapsack
            double fraction = (double)(W - currentWeight) / weight[i];
            totalProfit += profit[i] * fraction;
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    int profit[] = {6, 5, 4};
    int weight[] = {5, 4, 3};
    int n = sizeof(profit) / sizeof(profit[0]);
    int W = 7;

    double result = fractionalKnapsack(W, profit, weight, n);

    printf("Maximum profit in Fractional Knapsack = %.2f\n", result);

    return 0;
}

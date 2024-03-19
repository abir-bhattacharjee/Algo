#include <stdio.h>

int main() {
    int matrix[50][50];
    printf("Enter number of vertices in graph: ");
    int n;
    scanf("%d", &n);
    matrix[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter cost of [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int cost[n][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(matrix[i][j] == 0) cost[i][j] = 99;
            else cost[i][j] = matrix[i][j];
        }
    }

    int visited[10] = {0};
    visited[1] = 1;
    int mincost = 0;
    int no_edge = n - 1;
    while (no_edge > 0) {
        int min = 999; // Initialize min with a large value
        int a, b;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min && visited[i] != 0) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = a, v = b;
        if (visited[u] == 0 || visited[v] == 0) {
            printf("%d<-->%d : %d\n", u, v, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
        no_edge--;
    }
    printf("minimum cost %d\n", mincost);
    return 0;
}

#include <stdio.h>

#define MAX_VERTICES 50
#define INF 999

int find(int i, int parent[]) {
    while (parent[i] != 0) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j, int parent[]) {
    if (i != j) {
        parent[i] = j;
        return 1;
    }
    return 0;
}

int main() {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter number of vertices in graph: ");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter cost of [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int cost[MAX_VERTICES][MAX_VERTICES];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = matrix[i][j];
        }
    }

    int ne = 0;
    int mincost = 0;
    int parent[MAX_VERTICES] = {0};
    int a, b, v, u;

    while (ne < n - 1) {
        int min = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent)) {
            printf(" %d:%d <--> %d\n", min, a, b);
            mincost += min;
            ne++;
        }

        cost[a][b] = INF;
    }
    printf("Mincost : %d\n", mincost);
    return 0;
}

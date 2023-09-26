#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100
#define INF 999999

int graph[MAX_N][MAX_N];
int n;

int read_input() {
    FILE *file = fopen("MSTree.Inp", "r");
    if (file == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);
    return 0;
}

int prim_mst() {
    int min_weights[MAX_N];
    bool visited[MAX_N];
    for (int i = 0; i < n; i++) {
        min_weights[i] = INF;
        visited[i] = false;
    }

    min_weights[0] = 0;
    int total_weight = 0;

    for (int _ = 0; _ < n; _++) {
        int min_weight = INF;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && min_weights[v] < min_weight) {
                min_weight = min_weights[v];
                u = v;
            }
        }

        visited[u] = true;
        total_weight += min_weight;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 && graph[u][v] < min_weights[v]) {
                min_weights[v] = graph[u][v];
            }
        }
    }

    return total_weight;
}

int main() {
    if (read_input() != 0) {
        return 1;
    }

    int mst_weight = prim_mst();

    FILE *file = fopen("MSTree.Out", "w");
    if (file == NULL) {
        perror("Failed to open output file");
        return 1;
    }

    fprintf(file, "%d\n", mst_weight);
    fclose(file);

    return 0;
}

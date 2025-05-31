#include<stdio.h>
#include<stdlib.h>

void Hamiltonian_cycle(int graph[][20], int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) { 
            printf("Hamiltonian Cycle: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", path[i]);
            }
            printf("%d\n", path[0]); 
        }
        return;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(graph, path, pos, v, n)) {
            path[pos] = v;
            Hamiltonian_cycle(graph, path, pos + 1, n);
            path[pos] = -1; 
        }
    }
}

int isSafe(int graph[][20], int path[], int pos, int v, int n) {
    if (graph[path[pos - 1]][v] == 0) return 0; 
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return 0; 
    }
    return 1;
}
int main() {
    int n, graph[20][20], path[20];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0; 
    Hamiltonian_cycle(graph, path, 1, n);

    return 0;
}
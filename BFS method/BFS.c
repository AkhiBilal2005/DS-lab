#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX];
int n;
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void dfs(int v) {
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}
int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(start);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    dfs(0);
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("The graph is NOT connected\n");
            return 0;
        }
    }
    printf("The graph is CONNECTED\n");
    return 0;
}

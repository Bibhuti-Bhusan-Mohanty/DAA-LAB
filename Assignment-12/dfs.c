//program to take input for a graph using adjacency matrix,implement DFS algorithm to traverse the graph.

#include<stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int start){
    int i;
    visited[start] = 1;
    printf("%d ", start);
    for (i = 0; i < n; i++){
        if (adj[start][i] && !visited[i])
            dfs(i);
    }
}

int main(){
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    dfs(start);
    return 0;
}
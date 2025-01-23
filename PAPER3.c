#include<stdio.h>
#define MAX 100
void computeDegrees(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0};
    int outDegree[MAX] = {0};

    // Calculate in-degree and out-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                outDegree[i]++; // Outgoing edge from vertex i
                inDegree[j]++;  // Incoming edge to vertex j
            }
        }
    }

    // Print the in-degree and out-degree of each vertex
    printf("Vertex\tIn-Degree\tOut-Degree\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, inDegree[i], outDegree[i]);
    }
}
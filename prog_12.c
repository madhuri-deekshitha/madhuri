#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100  // Adjust this based on your problem size
#define INF 999  // Represent infinity

int choose(int dist[], int s[], int n) {
    int min = INF, j = -1, w;
    for (w = 1; w <= n; w++) {
        if (dist[w] < min && s[w] == 0) {
            min = dist[w];
            j = w;
        }
    }
    return j;
}

void spath(int v, int cost[][MAX], int dist[], int n) {
    int s[MAX];
    int w, num, u, i;
    
    // Initialize distances and set s[] for each vertex
    for (i = 1; i <= n; i++) {
        s[i] = 0;  // Not visited
        dist[i] = cost[v][i];  // Distance from source
    }
    
    s[v] = 1;  // Source is visited

    // Loop to find shortest paths
    for (num = 2; num <= n; num++) {
        u = choose(dist, s, n);  // Choose next closest vertex
        if (u == -1) break;  // No valid choice
        s[u] = 1;  // Mark as visited
        
        for (w = 1; w <= n; w++) {
            if (dist[u] + cost[u][w] < dist[w] && s[w] == 0) {
                dist[w] = dist[u] + cost[u][w];  // Update distance
            }
        }
    }
}

int main() {
    int n, dist[MAX], cost[MAX][MAX], i, j, v;
    double clk;
    clock_t starttime, endtime;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &v);
    
    starttime = clock();
    spath(v, cost, dist, n);
    endtime = clock();
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    
    printf("\nThe shortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d to %d = %d\n", v, i, dist[i]);
    }
    
    printf("Time taken is %f seconds\n", clk);
    
    return 0;
}
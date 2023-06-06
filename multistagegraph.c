#include <stdio.h>
#include <limits.h>
#define Max 10
void multistage_graph(int graph[Max][Max], int k, int n, int path[Max]) {
  int bcost[Max];
  int d[Max];

  bcost[1] = 0.0;

  for (int j = 2; j <= n; j++) {
    int r = -1;
    int min = INT_MAX;

    for (int i = 1; i <= n; i++) {
      if (graph[i][j] != 0 && bcost[i] + graph[i][j] < min) {
        min = bcost[i] + graph[i][j];
        r = i;
      }
    }

    bcost[j] = min;
    d[j] = r;
  }

  path[1] = 1;
  path[k] = n;

  for (int j = k - 1; j >= 2; j--) {
    path[j] = d[path[j + 1]];
  }
}


int main() {
  int n, k;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of stages: ");
  scanf("%d", &k);

  int graph[Max][Max];

  printf("Enter the cost matrix of the graph:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  int path[Max];
  multistage_graph(graph, k, n, path);

  printf("The minimum-cost path is: ");
  for (int i = 1; i <= k; i++) {
    printf("%d ", path[i]);
  }
  printf("\n");

  return 0;
}



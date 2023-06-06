#include <stdio.h>
#define Max 10

void bfs(int adj[Max][Max], int s, int n) {
  int visited[Max] = {0};  // Initialize visited array to all zeros
  int queue[Max],order[Max], front, rear;
  int count = 0,counter=0;
  
  visited[s] = 1;
  front = rear = 0;
  queue[rear] = s;
  order[count++]=s;
  
  while (counter < n) {
    int u = queue[front];
    front++;
    
    for (int i = 0; i < n; i++) {
      if (adj[u][i]==1 && visited[i] == 0) {
        visited[i] = 1;
        queue[++rear] = i;
        order[count++] = i;
      }
    }
    counter++;
  }
  printf("Order of visited vertices: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", order[i]);
  }
  printf("\n");
}

int main(){
  int adj[Max][Max],i,j,s,n;
  printf("No. of elements");
  scanf("%d",&n);
  printf("Source Element:");
  scanf("%d",&s);
  printf("Adjacency Matrix :");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&adj[i][j]);
    }
  }
  bfs(adj,s,n);
}
#include <stdio.h>
int parent[10];

int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}

int uni(int i, int j){
    int u,v;
    u=find(i);
    v=find(j);
    if(u!=v){
        parent[v]=u;
        return 1;
    }
    return 0;
}

int main(){
    int i,j,cost[10][10],n,count=1,min,u,v,min_cost=0;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Cost matrix is: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(cost[i][j]==0){
                cost[i][j]=9999;
            }
        }
    }

  while(count <n){
    min=9999;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    if(uni(u,v)){
        printf("%d %d->%d = %d ",count,u,v,min);
        count++;
        min_cost+=min;

    }
    cost[u][v]=cost[v][u]=9999;
  }
  printf("Cost is : %d",min_cost);
}
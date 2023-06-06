#include <stdio.h>

void prims(int cost[10][10],int n){
    int visited[10],min,count=1,i,j,u,v,min_cost=0;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    visited[0]=1;
    while(count< n ){
         min=9999;
        for(i=0;i<n;i++){
           
            if(visited[i]==1){
                for(j=0;j<n;j++){
                    if(min>cost[i][j] && visited[j]==0){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        visited[v]=1;
        printf("%d  %d->%d = %d\n",count,u,v,min);
        cost[u][v]=cost[v][u];
        min_cost+=min;
        count++;
        
    }
    printf("Minimum cost is %d",min_cost);
}

int main(){
    int i,j,n,cost[10][10];
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Cost matrix is:");
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
    prims(cost,n);
}
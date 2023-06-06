#include <stdio.h>

void dijikstra(int cost[10][10], int distance[10], int n, int s){
    int i,v,visited[10],min,count=1;
    for(i=0;i<n;i++){
        visited[i]=0;
        distance[i]=cost[s][i];
    }
    visited[s]=1;
    distance[s]=0;

    while(count<=n){
        min=9999;
        for(i=0;i<n;i++){
            if(min>distance[i] && visited[i]==0){
                min= distance[i];
                v=i;
            }
        }
        for(i=0;i<n;i++){
            if(distance[i]>distance[v]+cost[v][i]){
                distance[i]=distance[v]+cost[v][i];
            }
        }
        count++;
    }
}
int main(){
    int i,j,cost[10][10],n,distance[10],s;
    printf("Number of elements are:");
    scanf("%d",&n);
    printf("Source element is :");
    scanf("%d",&s);
    printf("Cost matrix is:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                scanf("%d",&cost[i][j]);

        }
    }
    for ( i = 0; i < n; i++)
    {
        for(j=0;j<n;j++){
            if(cost[i][j]==0){
                cost[i][j]=9999;
            }
        }
    }

    dijikstra(cost,distance,n,s);
    for(i=0;i<n;i++){
        if(i != s){
            printf("%d -> %d = %d\n",s,i,distance[i]);
        }
    }
    return 0;
}
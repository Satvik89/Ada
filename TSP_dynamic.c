#include <stdio.h>

int x,visited[10];

int tsp(int c, int cost[20][20], int n){
    int i,next=9999,temp,min=9999;
    for(i=0;i<n;i++){
        if(cost[c][i]!=0 && visited[i]==0){
            if(cost[c][i]<min){
                min=cost[c][i]+cost[i][0];
            }
            temp=cost[c][i];
            next=i;
        }
    }
    if(min != 9999){
        x+=temp;
    }
    return next;
}

void min_cost(int i, int cost[20][20],int n){
    int next_vertex;
    visited[i]=1;
    printf("%d ",i+1);
    next_vertex=tsp(i,cost,n);
    if(next_vertex == 9999){
        next_vertex=0;
        printf("%d\n",next_vertex+1);
        x+=cost[i][next_vertex];
        return;
    }
    min_cost(next_vertex,cost,n);
}

int main(){
    int i,j,n,cost[20][20];
    printf("Enter the number of vertex");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
        visited[i]=0;
    }
  
    printf("Path");
    min_cost(0,cost,n);
    printf("Minimum cost is: %d",x);

}
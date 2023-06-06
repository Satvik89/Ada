#include <stdio.h>

int main(){
    int i,j,k,cost[10][10],n;
    printf("Number of elements are:");
    scanf("%d",&n);
    printf("Cost matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][j]>cost[i][k]+cost[k][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(cost[i][j]==99){
                printf("inf ");
            }
            else{
                printf("%d ",cost[i][j]);
            }
        }
        printf("\n");
    }
}
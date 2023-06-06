#include <stdio.h>
int n,m ,cost[10][10],x[10];
int next_value(int k){
    do{
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0){
            return 0;
        }
        int j;
        for(j=1;j<=n;j++){
            if(cost[k][j]!=0 && x[k]==x[j]){
                break;
            }
        }
        if(j==n+1){
            return 1;
        }
    }while(1);
}

int m_color(int k){
    int i;
    do{
        next_value(k);
        if(x[k]==0){
            return 0;
        }
        if(k==n){
            for(i=0;i<n;i++){
                printf("%d",x[i]);
            }
            printf("\n");
        }
        else{
            m_color(k+1);
        }
        
    }while(1);
}


int main(){
    int i,j;
    printf("Number of elements");
    scanf("%d",&n);
    printf("Color");
    scanf("%d",&m);
    printf("Cost matrix is:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    m_color(1);
}
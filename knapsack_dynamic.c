#include <stdio.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
    }
int knapsack(int val[10], int wt[], int n, int W){
    int k[10][10],i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=w){
                k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }

        }
    }
    
    return k[n][W];
}

int knapsack2( int wt[], int n, int W){
    int k[10][10],i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=w){
                k[i][w]=max(wt[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }

        }
    }
    
    return k[n][W];
}

int main(){
    int  val[10],wt[10],W,n,i,profit,max_weight;
    printf("Number of elements are:");
    scanf("%d",&n);
    printf("Profit:");
    for(i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Weight:");
    for(i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Maximum Capacity:");
    scanf("%d",&W);
    profit = knapsack(val,wt,n,W);
    printf("Profit is : %d\n",profit);
    max_weight=knapsack2(wt,n,W);
    printf("Weight is : %d",max_weight);
}
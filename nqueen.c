#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int col[10];

int place(int i  , int k){
    int j;
   for(j=1;j<k;j++){
    if(col[j]==i || (abs(col[j]-i))==abs(j-k)){
        return 0;
    }
   }
   return 1;
} 
void n_queens(int k, int n){
   int i,j;
   for(i=1;i<=n;i++){
      if(place(i,k)==1){
        col[k]=i;
        if(k==n){
            for(j=1;j<=n;j++){
                printf("%d ",col[j]);
            }
            printf("\n");
        }
        else{
            n_queens(k+1,n);
        }
      }
   }
}


int main(){
    int k,n;
    printf("Number of queens");
    scanf("%d",&n);
    printf("Starting queen");
    scanf("%d",&k);
    n_queens(k,n);
}
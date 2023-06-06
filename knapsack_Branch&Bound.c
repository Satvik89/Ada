#include <stdio.h>

int bound(int currentProfit, int currentWeight, int weight[10], int profit[10], int k, int m, int n) {
  int i, b = currentProfit, c = currentWeight;
  for (i = k + 1; i <= n; i++) {
    if (c + weight[i] <= m) {
      c = c + weight[i];
      b = b - profit[i];
    }
  }
  return b;
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}
void knapsack(int weight[10], int profit[10], int n, int m) {
  int i, j, k, maxProfit = 0, currentProfit, currentWeight, upperBound;
  int dp[n + 1][m + 1];

  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (weight[i - 1] <= j) {
        dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  for (i = 1; i <= n; i++) {
    if (dp[i][m] > maxProfit) {
      maxProfit = dp[i][m];
      k = i;
    }
  }

  while (k > 0) {
    currentProfit = maxProfit;
    currentWeight = m;
    for (i = k; i >= 1; i--) {
      if (currentWeight - weight[i - 1] >= 0) {
        currentProfit = currentProfit - profit[i - 1];
        currentWeight = currentWeight - weight[i - 1];
      }
    }

    upperBound = bound(currentProfit, currentWeight, weight, profit, k - 1, m, n);

    if (upperBound >= maxProfit) {
      maxProfit = upperBound;
    } 
    k--;
  }

  printf("Maximum profit = %d\n", maxProfit);
}

int main(){
    int  val[10],wt[10],W,n,i;
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
    knapsack(wt,val,n,W);
   
}

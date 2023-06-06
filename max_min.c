
#include <stdio.h>
void max_min(int arr[10], int low, int high, int *max, int *min){
    if(low==high){
       *max=*min=arr[0];
    }
    else if(low==high-1){
        if(arr[low]>arr[high]){
            *max=arr[low];
            *min=arr[high];
        }
        else{
            *max=arr[high];
            *min=arr[low];
        }
    }
    else{
        int mid=(low+high)/2;
        int max1,min1;
        max_min(arr,low,mid,max,min);
        max_min(arr,mid+1,high,&max1,&min1);
        if(*max<max1){
            *max=max1;
        }
        if(*min>min1){
            *min=min1;
        }
    }
}

int main()
{
  int i,arr[10],n,max,min;
  printf("Number of array:");
  scanf("%d",&n);
  printf("array is:");
  for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
  }
  max_min(arr,0,n-1,&max,&min);
  printf("Max is: %d",max);
  printf("Min is: %d",min);
}


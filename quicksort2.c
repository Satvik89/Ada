#include <stdio.h>
void quicksort(int arr[10], int low, int high){
    int pivot=arr[low],i=low,j=high,temp;
    if(low<high){
        while(i<=j){
            if(pivot < arr[j]){
                j--;
            }
            if(pivot > arr[i]){
                i++;
            }
            if(i<=j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
        }
          quicksort(arr,low,j);
    quicksort(arr,i,high);
    }
  

}

int main(){
    int i,arr[10],n;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Array is:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Array is:");
    for ( i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    
}
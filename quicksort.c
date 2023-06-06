#include <stdio.h>

int partition(int arr[10], int low, int high){
    int pivot = arr[high],i=low,j,temp;
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    temp=arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    return i;
}

void quicksort(int arr[10], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
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
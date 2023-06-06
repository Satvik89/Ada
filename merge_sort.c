#include <stdio.h>

void merge(int arr[10], int low, int mid, int high){
    int i=low,j=mid+1,k=low,temp[10];
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            temp[k]=arr[j];
            j++;
        }
        else{
            temp[k]=arr[i];
            i++;
        }
        k++;
    }
    
    if(i>mid){
        while(j<=high){
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
 for(i=0;i<k;i++){
    arr[i]=temp[i];
 }
}

void merge_sort(int arr[10],int low, int high){
    if(low<high){
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
}

int main()
{
    int i,n,arr[10];
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Array is:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("Array is :");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
